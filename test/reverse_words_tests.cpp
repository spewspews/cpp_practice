#include <gtest/gtest.h>

#include <reverse_words.h>

class ReverseWordsTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(ReverseWordsTests, FirstExample) {
    std::vector<char> v({'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ',
                         'b', 'l', 'u', 'e'});
    s.reverseWords(v);
    ASSERT_EQ(v, std::vector({'b', 'l', 'u', 'e', ' ', 'i', 's', ' ', 's', 'k',
                              'y', ' ', 't', 'h', 'e'}));
}

TEST_F(ReverseWordsTests, OneWord) {
    std::vector<char> v({'t', 'h', 'e'});
    s.reverseWords(v);
    ASSERT_EQ(v, std::vector({'t', 'h', 'e'}));
}

TEST_F(ReverseWordsTests, ThreeWordsFirst) {
    std::vector<char> v({'1', ' ', '2', ' ', '3'});
    s.reverseWords(v);
    ASSERT_EQ(v, std::vector({'3', ' ', '2', ' ', '1'}));
}

TEST_F(ReverseWordsTests, ThreeWords) {
    std::vector<char> v({'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's'});
    s.reverseWords(v);
    ASSERT_EQ(v,
              std::vector({'i', 's', ' ', 's', 'k', 'y', ' ', 't', 'h', 'e'}));
}
