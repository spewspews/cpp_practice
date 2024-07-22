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

TEST_F(RegularExpressionTests, Mississippi) {
    ASSERT_FALSE(s.isMatch("mississippi", "mis*is*p*."));
}

TEST_F(RegularExpressionTests, Failing) {
    ASSERT_TRUE(s.isMatch("aaa", "ab*a*c*a"));
}

TEST_F(RegularExpressionTests, FailingAgain) {
    ASSERT_TRUE(s.isMatch("aa", "a*"));
}

TEST_F(RegularExpressionTests, FailingOnceAgain) {
    ASSERT_TRUE(s.isMatch("a", "ab*"));
}

TEST_F(RegularExpressionTests, Dot) { ASSERT_TRUE(s.isMatch("abc", "a.c")); }

TEST_F(RegularExpressionTests, DotStar) {
    ASSERT_TRUE(s.isMatch("abdka;lkjefc", "a.*c"));
}

TEST_F(RegularExpressionTests, DotStarAgain) {
    ASSERT_FALSE(s.isMatch("abdka;lkjefc", "a.*d"));
}
