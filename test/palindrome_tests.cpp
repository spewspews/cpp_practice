#include <gtest/gtest.h>

#include <palindrome.h>

class PalindromeTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(PalindromeTests, FirstExample) {
    ASSERT_EQ(s.isPalindrome("A man, a plan, a canal: Panama"), true);
}

TEST_F(PalindromeTests, Empty) { ASSERT_EQ(s.isPalindrome(""), true); }

TEST_F(PalindromeTests, One) { ASSERT_EQ(s.isPalindrome("a"), true); }

TEST_F(PalindromeTests, Two) { ASSERT_EQ(s.isPalindrome("aA"), true); }

TEST_F(PalindromeTests, NotTwo) { ASSERT_EQ(s.isPalindrome("aB"), false); }

TEST_F(PalindromeTests, Crash) { ASSERT_EQ(s.isPalindrome(".,"), true); }
