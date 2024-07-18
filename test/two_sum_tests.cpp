#include <gtest/gtest.h>

#include <two_sum.h>

class TwoSumTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(TwoSumTests, FirstExample) {
    std::vector<int> v({2, 7, 11, 15});
    ASSERT_EQ(s.twoSum(v, 9), decltype(s.twoSum(v, 9))({0, 1}));
}

TEST_F(TwoSumTests, Failing) {
    std::vector<int> v({3, 2, 4});
    ASSERT_EQ(s.twoSum(v, 6), decltype(s.twoSum(v, 6))({1, 2}));
}
