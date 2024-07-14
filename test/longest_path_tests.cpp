#include <gtest/gtest.h>

#include <longest_path.h>

class LongestPathTest : public testing::Test {
  protected:
    Solution s;
};

TEST_F(LongestPathTest, FirstExample) {
    std::vector<int> parent({-1, 0, 0, 1, 1, 2});
    std::string values = "abacbe";
    ASSERT_EQ(s.longestPath(parent, values), 3);
}

TEST_F(LongestPathTest, SecondExample) {
    std::vector<int> parent({-1, 0, 0, 0});
    std::string values = "aabc";
    ASSERT_EQ(s.longestPath(parent, values), 3);
}

TEST_F(LongestPathTest, FailingExample) {
    std::vector<int> parent({-1, 0, 0, 2, 3, 2, 4});
    std::string values = "aaaxaax";
    ASSERT_EQ(s.longestPath(parent, values), 4);
}
