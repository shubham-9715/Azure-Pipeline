#include "math_utils.h"
#include <gtest/gtest.h>

TEST(AdditionTest, SimpleCases) {
    EXPECT_EQ(add(5, 5), 10);
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(-1, 1), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
