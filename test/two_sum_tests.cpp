#include <gtest/gtest.h>

#include <two_sum.h>

class TwoSumTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(TwoSumTests, FirstExample) {
    std::vector v({2, 7, 11, 15});
    ASSERT_EQ(s.twoSum(v, 9), std::vector({0, 1}));
}

TEST_F(TwoSumTests, Failing) {
    std::vector v({3, 2, 4});
    ASSERT_EQ(s.twoSum(v, 6), std::vector({1, 2}));
}
