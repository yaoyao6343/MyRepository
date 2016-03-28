/**
 * @file: rotate_string.c
 * @brief: Move first n characters to the end of string. eg: abcdef -> defabc
 *
 * @date: 2016.03.24
 *
 * @note: T: O(n), S: O(1)
 */

#include <stdio.h>
#include "gtest/gtest.h"

void reverse_string(char *s, int idx_begin, int idx_end)
{
    char tmp = 0;
    while (idx_begin < idx_end)
    {
        tmp = s[idx_begin];
        s[idx_begin++] = s[idx_end];
        s[idx_end--] = tmp;
    }
}

/**
 * @param s: string
 * @param n: Move n characters from head to tail.
 */
void left_rotate_string(char *s, int n)
{
    int len = strlen(s);
    reverse_string(s, 0, n - 1);
    reverse_string(s, n, len - 1);
    reverse_string(s, 0, len - 1);
}


/**
 ******************************************************************************
 * Unit tests
 ******************************************************************************
 */
TEST(RotateStringTest, ReverseStringFunc)
{
    char s[8] = "abcdef";

    reverse_string(s, 0, 2);
    EXPECT_STREQ(s, "cbadef");

    strncpy(s, "abcdef", 6);
    reverse_string(s, 0, 5);
    EXPECT_STREQ(s, "fedcba");

    strncpy(s, "abcdef", 6);
    reverse_string(s, 1, 4);
    EXPECT_STREQ(s, "aedcbf");

    strncpy(s, "abcdef", 6);
    reverse_string(s, 3, 3);
    EXPECT_STREQ(s, "abcdef");

    strncpy(s, "abcdef", 6);
    reverse_string(s, 4, 5);
    EXPECT_STREQ(s, "abcdfe");
}

TEST(RotateStringTest, LeftRotateStringFunc)
{
    char s[64] = "http://taop.marchtea.com/01.01.html";

    left_rotate_string(s, 5);
    EXPECT_STREQ(s, "//taop.marchtea.com/01.01.htmlhttp:");

    strncpy(s, "http://taop.marchtea.com/01.01.html", sizeof(s));
    left_rotate_string(s, 17);
    EXPECT_STREQ(s, "tea.com/01.01.htmlhttp://taop.march");
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

