#include <stdio.h>
#include "gtest/gtest.h"

/**
 * Function
 */
int add_(int a, int b)
{
    return a + b;
}


/**
 * Test suite
 */
class FooEnvironment : public testing::Environment
{
public:
    virtual void SetUp()
    {
        std::cout << "===========================================" << std::endl;
        std::cout << "TestSuite" << std::endl;
        std::cout << "===========================================" << std::endl;
    }
    virtual void TearDown()
    {
        // std::cout << "TestSuite1 Teardown" << std::endl;
        std::cout << "===========================================" << std::endl;
    }
};

class FooTest : public testing::Test
{
protected:
    static void SetUpTestCase()
    {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "SetUpTestCase" << std::endl;
    }
    static void TearDownTestCase()
    {
        std::cout << "TearDownTestCase" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
    }
};


TEST_F(FooTest, NG001)
{
    EXPECT_EQ(2, add_(1, 1));
    EXPECT_NE(2, add_(0, 1));
}

TEST_F(FooTest, NG002)
{
    EXPECT_LT(1, add_(1, 1));
    EXPECT_GT(4, add_(2, 1));
}


/**
 * main function
 */
int main(int argc, char **argv)
{
    // testing::AddGlobalTestEnvironment(new FooEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
