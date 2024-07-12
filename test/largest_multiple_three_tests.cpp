#include <gtest/gtest.h>

#include <largest_multiple_three.h>

class LargestMultipleThreeTests : public testing::Test {
protected:
  Solution s;
};

TEST_F(LargestMultipleThreeTests, DigitSums) {
  ASSERT_EQ(s.digit_sum_of_int(23), 5);
  ASSERT_EQ(s.digit_sum_of_int(97), 7);
}

TEST_F(LargestMultipleThreeTests, DigitSumsVector) {
  {
    std::vector<int> v({9, 7, 1});
    ASSERT_EQ(s.digit_sum_of_vector(v), 8);
  }
  {
    std::vector<int> v({8, 6, 7, 1, 0});
    ASSERT_EQ(s.digit_sum_of_vector(v), 4);
  }
}

TEST_F(LargestMultipleThreeTests, Just3Returns3) {
  std::vector<int> v({3});
  ASSERT_EQ(s.largestMultipleOfThree(v), "3");
}

TEST_F(LargestMultipleThreeTests, Returns981) {
  std::vector<int> v({8, 1, 9});
  ASSERT_EQ(s.largestMultipleOfThree(v), "981");
}

TEST_F(LargestMultipleThreeTests, Returns8760) {
  std::vector<int> v({8, 6, 7, 1, 0});
  ASSERT_EQ(s.largestMultipleOfThree(v), "8760");
}

TEST_F(LargestMultipleThreeTests, Returns3) {
  std::vector<int> v({3, 2, 2});
  ASSERT_EQ(s.largestMultipleOfThree(v), "3");
}
