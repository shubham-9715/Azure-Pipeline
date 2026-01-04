#include <gtest/gtest.h>
#include "calculator.h"

TEST(CalculatorTest, AddTest) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(CalculatorTest, SubTest) {
    EXPECT_EQ(subtract(5, 2), 3);
}
