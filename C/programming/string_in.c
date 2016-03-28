/**
 * @file: string_in.c
 * @brief: Check if string A include string B. eg: 'ABCD' includes 'AB', 'CDA',
 *      'DDC' and so on.
 *
 * @date: 2016.03.24
 *
 * @note: Length of string A is bigger than string B.
 */

#include <stdio.h>
#include "gtest/gtest.h"

#define RET_YES    (0)
#define RET_NO     (1)

/**
 * @note: T: O(n*m)
 */
int string_contain1(char *sa, char *sb)
{
    int i = 0, j = 0;
    int sa_len = strlen(sa), sb_len = strlen(sb);

    for (i = 0; i < sb_len; i++)
    {
        for (j = 0; j < sa_len && sb[i] != sa[j]; j++)
            ;
        if (j >= sa_len)
        {
            return RET_NO;
        }
    }
    return RET_YES;
}

/**
 * @note: All characters are uper character. T: O(n+m)
 */
int string_contain2(char *sa, char *sb)
{
    const int p[26] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97, 101};
    int sa_len = strlen(sa), sb_len = strlen(sb);
    int i = 0, x = 0;
    long f = 1;

    for (i = 0; i < sa_len; i++)
    {
        x = p[sa[i] - 'A'];
        if (f % x)
        {
            f *= x;
        }
    }
    for (i = 0; i < sb_len; i++)
    {
        x = p[sb[i] - 'A'];
        if (f % x)
        {
            return RET_NO;
        }
    }
    return RET_YES;
}


/**
 * @note: All characters are uper character. T: O(n+m)
 */
int string_contain3(char *sa, char *sb)
{
    int sa_len = strlen(sa), sb_len = strlen(sb);
    int i = 0, hash = 0;

    for (i = 0; i < sa_len; i++)
    {
        hash |= (1 << (sa[i] - 'A'));
    }
    for (i = 0; i < sb_len; i++)
    {
        if (((1 << (sb[i] - 'A')) & hash) == 0)
        {
            return RET_NO;
        }
    }
    return RET_YES;
}

/**
 * @note: T: O(n+m)
 */
int string_contain4(char *sa, char *sb)
{
    int sa_len = strlen(sa), sb_len = strlen(sb);
    char hs[128] = {0};
    int i = 0;

    for (i = 0; i < sa_len; i++)
    {
        hs[(sa[i])] = 1;
    }

    for (i = 0; i < sb_len; i++)
    {
        if (hs[sb[i]] != 1)
        {
            return RET_NO;
        }
    }
    return RET_YES;
}


/**
 ******************************************************************************
 * Unit tests
 ******************************************************************************
 */
TEST(StringInTest, Func1)
{    char a[16] = "Hellow world", b[16] = {0};

    strncpy(b, "world", sizeof(b));
    printf("'%s' contains '%s'\n", a, b);
    EXPECT_EQ(string_contain1(a, b), RET_YES);

    strncpy(b, "HELLO", sizeof(b));
    printf("'%s' doesn't contains '%s'\n", a, b);
    EXPECT_EQ(string_contain1(a, b), RET_NO);

    strncpy(b, "Hwld", sizeof(b));
    printf("'%s' contains '%s'\n", a, b);
    EXPECT_EQ(string_contain1(a, b), RET_YES);
}

TEST(StringInTest, Func2)
{
    char a[16] = "HELLOWORLD", b[16] = {0};

    strncpy(b, "WORD", sizeof(b));
    printf("'%s' contains '%s'\n", a, b);
    EXPECT_EQ(string_contain2(a, b), RET_YES);

    strncpy(b, "HELZZ", sizeof(b));
    printf("'%s' doesn't contains '%s'\n", a, b);
    EXPECT_EQ(string_contain2(a, b), RET_NO);

    strncpy(b, "HWLD", sizeof(b));
    printf("'%s' contains '%s'\n", a, b);
    EXPECT_EQ(string_contain2(a, b), RET_YES);
}

TEST(StringInTest, Func3)
{
    char a[16] = "HELLOWORLD", b[16] = {0};

    strncpy(b, "WORD", sizeof(b));
    printf("'%s' contains '%s'\n", a, b);
    EXPECT_EQ(string_contain3(a, b), RET_YES);

    strncpy(b, "HELZZ", sizeof(b));
    printf("'%s' doesn't contains '%s'\n", a, b);
    EXPECT_EQ(string_contain3(a, b), RET_NO);

    strncpy(b, "HWLD", sizeof(b));
    printf("'%s' contains '%s'\n", a, b);
    EXPECT_EQ(string_contain3(a, b), RET_YES);
}

TEST(StringInTest, Func4)
{
    char a[128] = "http://taop.marchtea.com/01.02.html", b[64] = {0};

    strncpy(b, "//.l", sizeof(b));
    printf("'%s' contains '%s'\n", a, b);
    EXPECT_EQ(string_contain4(a, b), RET_YES);

    strncpy(b, "HELZZ", sizeof(b));
    printf("'%s' doesn't contains '%s'\n", a, b);
    EXPECT_EQ(string_contain4(a, b), RET_NO);

    strncpy(a, "~!@#$%^&*()_+-={}[]|\\\"';?><,./`124dX:", sizeof(a));
    puts(a);
    strncpy(b, "HELZZ", sizeof(b));
    printf("'%s' doesn't contains '%s'\n", a, b);
    EXPECT_EQ(string_contain4(a, b), RET_NO);

}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

