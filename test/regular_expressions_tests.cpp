#include <gtest/gtest.h>

#include <regular_expressions.h>

class RegularExpressionTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(RegularExpressionTests, FirstExample) { ASSERT_TRUE(s.isMatch("", "")); }

TEST_F(RegularExpressionTests, SecondExample) {
    ASSERT_FALSE(s.isMatch("hello", ""));
}

TEST_F(RegularExpressionTests, Failing) {
    ASSERT_TRUE(s.isMatch("aaa", "ab*a*c*a"));
}
