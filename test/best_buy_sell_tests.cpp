#include <gtest/gtest.h>

#include <best_buy_sell.h>

class BestBuySellTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(BestBuySellTests, FirstExample) {
    std::vector<int> v({7, 1, 5, 3, 6, 4});
    ASSERT_EQ(s.maxProfit(v), 5);
}
