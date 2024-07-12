#include <gtest/gtest.h>

#include <comb_and.h>

class CombinationsAndTest : public testing::Test {
  protected:
    Solution s;
};

TEST_F(CombinationsAndTest, Trivial) {
    {
        std::vector<int> v({1});
        ASSERT_EQ(s.largestCombination(v), 1);
    }
}

TEST_F(CombinationsAndTest, TrivialFailed) {
    {
        std::vector<int> v({8388608});
        ASSERT_EQ(s.largestCombination(v), 1);
    }
}

TEST_F(CombinationsAndTest, FirstExample) {
    {
        std::vector<int> v({16, 17, 71, 62, 12, 24, 14});
        ASSERT_EQ(s.largestCombination(v), 4);
    }
}

TEST_F(CombinationsAndTest, FailedExample) {
    {
        std::vector<int> v(
            {16, 16, 48, 71, 62, 12, 24, 14, 17, 18, 19, 20, 10000});
        ASSERT_EQ(s.largestCombination(v), 10);
    }
}

TEST_F(CombinationsAndTest, BigExample) {
    {
        std::vector<int> v({33, 93, 31, 99, 74, 37, 3,  4,   2,  94,
                            77, 10, 75, 54, 24, 95, 65, 100, 41, 82,
                            35, 65, 38, 49, 85, 72, 67, 21,  20, 31});
        ASSERT_EQ(s.largestCombination(v), 18);
    }
}
