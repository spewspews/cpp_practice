#include <gtest/gtest.h>

#include <longest_palindrome.h>

class LongestPalindromeTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(LongestPalindromeTests, FirstExample) {
    ASSERT_EQ(s.longestPalindrome(""), "");
}

TEST_F(LongestPalindromeTests, OneChar) {
    ASSERT_EQ(s.longestPalindrome("a"), "a");
}

TEST_F(LongestPalindromeTests, Odd) {
    ASSERT_EQ(s.longestPalindrome("aba"), "aba");
}

TEST_F(LongestPalindromeTests, Even) {
    ASSERT_EQ(s.longestPalindrome("abba"), "abba");
}

TEST_F(LongestPalindromeTests, Longer) {
    ASSERT_EQ(s.longestPalindrome("abacddc"), "cddc");
}

TEST_F(LongestPalindromeTests, LongerOdd) {
    ASSERT_EQ(s.longestPalindrome("abacdadc"), "cdadc");
}
