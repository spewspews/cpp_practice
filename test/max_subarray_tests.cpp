#include <gtest/gtest.h>

#include <max_subarray.h>

class MaxSubarrayTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(MaxSubarrayTests, FirstExample) {
    std::vector<int> v({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    ASSERT_EQ(s.maxSubArray(v), 6);
}

TEST_F(MaxSubarrayTests, Another) {
    std::vector<int> v({-2, 1000000000, -3, 4, -1, 2, 1, -5, 4});
    ASSERT_EQ(s.maxSubArray(v), 1000000003);
}
