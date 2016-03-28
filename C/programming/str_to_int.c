/**
 * @file: str_to_int.c
 * @brief: Convert string to integer.
 *
 * @date: 2016.03.28
 */

#include <stdio.h>
#include "gtest/gtest.h"

static const int MAX_INT = (int)((unsigned)~0 >> 1);
static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;

int str_to_int(const char *str)
{
    unsigned int n = 0;

    if (str == NULL)
    {
        return 0;
    }

    while (isspace(*str))
    {
        str++;
    }

    int sign = 1;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
        {
            sign = -1;
        }
        str++;
    }

    int c = 0;
    while (isdigit(*str))
    {
        c = *str - '0';
        if (sign > 0 && (n > (MAX_INT / 10) || (n == (MAX_INT / 10) && c > (MAX_INT % 10))))
        {
            n = MAX_INT;
            break;
        }
        else if (sign < 0 && (n > -(MIN_INT / 10) || (n == -(MIN_INT / 10) && c > -(MIN_INT % 10))))
        {
            n = MIN_INT;
            break;
        }
        n = n * 10 + c;
        str++;
    }
    return sign > 0 ? n : -n;
}


/**
 ******************************************************************************
 * Unit tests
 ******************************************************************************
 */
TEST(StrToInt, Normal)
{
    char s[16] = {0};

    EXPECT_EQ(str_to_int(s), 0);

    strncpy(s, "287492", sizeof(s));
    EXPECT_EQ(str_to_int(s), 287492);

    strncpy(s, "   287492", sizeof(s));
    EXPECT_EQ(str_to_int(s), 287492);

    strncpy(s, "  -287492", sizeof(s));
    EXPECT_EQ(str_to_int(s), -287492);

    strncpy(s, "   +287492", sizeof(s));
    EXPECT_EQ(str_to_int(s), 287492);

    strncpy(s, "   28d7492", sizeof(s));
    EXPECT_EQ(str_to_int(s), 28);
}
TEST(StrToInt, MaxInt)
{
    char s[16] = "  2147483647";

    EXPECT_EQ(str_to_int(s), 2147483647);

    strncpy(s, "2147483646", sizeof(s));
    EXPECT_EQ(str_to_int(s), 2147483646);

    strncpy(s, "2147483648", sizeof(s));
    EXPECT_EQ(str_to_int(s), 2147483647);

    strncpy(s, "21474836x57", sizeof(s));
    EXPECT_EQ(str_to_int(s), 21474836);
}
TEST(StrToInt, MinInt)
{
    char s[16] = "  -2147483648";

    EXPECT_EQ(str_to_int(s), -2147483648);

    strncpy(s, "-2147483647", sizeof(s));
    EXPECT_EQ(str_to_int(s), -2147483647);

    strncpy(s, "-2147483649", sizeof(s));
    EXPECT_EQ(str_to_int(s), -2147483648);

    strncpy(s, "  -2147483657", sizeof(s));
    EXPECT_EQ(str_to_int(s), -2147483648);

    strncpy(s, "  -21474d83657", sizeof(s));
    EXPECT_EQ(str_to_int(s), -21474);
}
TEST(StrToInt, All)
{
    char s[16] = {0};
    unsigned int i = 0;

    for (i = 0; i <= 2147483; i++)
    {
        snprintf(s, 16, "%u", i);
        EXPECT_EQ(str_to_int(s), i);
    }
}

int main(int argc, char **argv)
{
    printf("MAX_INT: %u, %d, %d;\nMIN_INT: %u, %d, %d;\n",
        MAX_INT, MAX_INT / 10, MAX_INT % 10, MIN_INT, MIN_INT / 10, MIN_INT % 10);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


