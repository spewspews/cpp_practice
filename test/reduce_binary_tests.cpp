#include <gtest/gtest.h>

#include <reduce_binary.h>

class ReduceBinaryTest : public testing::Test {
  protected:
    Solution s;
};

TEST_F(ReduceBinaryTest, OneIs0) { ASSERT_EQ(s.numSteps("1"), 0); }

TEST_F(ReduceBinaryTest, LeadingZeros) {
    ASSERT_EQ(s.numSteps("1000"), 3);
    std::string str("1");
    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(s.numSteps(str), i);
        str.push_back('0');
    }
}

TEST_F(ReduceBinaryTest, AllOnes) {
    ASSERT_EQ(s.numSteps("11"), 3);
    std::string str("11");
    for (int i = 2; i < 10; ++i) {
        ASSERT_EQ(s.numSteps(str), i + 1);
        str.push_back('1');
    }
}

TEST_F(ReduceBinaryTest, ZeroGroups) {
    // 101 -> 110 -> 11 -> 100 -> 10 -> 1 : 5
    ASSERT_EQ(s.numSteps("101"), 5);
    // 1001 -> 1010 -> 101 -> 110 -> 11 -> 100 -> 10 -> 1 : 7
    ASSERT_EQ(s.numSteps("1001"), 7);
}

TEST_F(ReduceBinaryTest, TwoZeros) { ASSERT_EQ(s.numSteps("10101"), 8); }

TEST_F(ReduceBinaryTest, FailedTest) { ASSERT_EQ(s.numSteps("11000"), 6); }
