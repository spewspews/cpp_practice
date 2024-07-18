#include <gtest/gtest.h>

#include <reverse_words1.h>

class ReverseWordsSimpleTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(ReverseWordsSimpleTests, FirstExample) {
    ASSERT_EQ(s.reverseWords("the sky is blue"), "blue is sky the");
}

TEST_F(ReverseWordsSimpleTests, Second) {
    ASSERT_EQ(s.reverseWords("  hello world  "), "world hello");
}
