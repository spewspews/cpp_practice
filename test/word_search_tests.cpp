#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <word_search.h>

class WordSearchTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

using testing::UnorderedElementsAre;
using testing::WhenSorted;

TEST_F(WordSearchTests, FirstExample) {
    std::vector<std::vector<char>> board({{'o', 'a', 'a', 'n'},
                                          {'e', 't', 'a', 'e'},
                                          {'i', 'h', 'k', 'r'},
                                          {'i', 'f', 'l', 'v'}});
    std::vector<std::string> words({"oath", "pea", "eat", "rain"});
    ASSERT_THAT(s.findWords(board, words),
                WhenSorted(UnorderedElementsAre("eat", "oath")));
}

TEST_F(WordSearchTests, Failure) {
    std::vector<std::vector<char>> board({{'o', 'a', 'b', 'n'},
                                          {'o', 't', 'a', 'e'},
                                          {'a', 'h', 'k', 'r'},
                                          {'a', 'f', 'l', 'v'}});
    std::vector<std::string> words({"oa", "oaa"});
    ASSERT_THAT(s.findWords(board, words),
                WhenSorted(UnorderedElementsAre("oa", "oaa")));
}

TEST_F(WordSearchTests, EasyFailure) {
    std::vector<std::vector<char>> board({{'a', 'a'}});
    std::vector<std::string> words({"aa"});
    ASSERT_THAT(s.findWords(board, words),
                WhenSorted(UnorderedElementsAre("aa")));
}

TEST_F(WordSearchTests, AnotherFailure) {
    std::vector<std::vector<char>> board({{'a', 'b'}, {'a', 'a'}});
    std::vector<std::string> words(
        {"aba", "baa", "bab", "aaab", "aaa", "aaaa", "aaba"});
    ASSERT_THAT(
        s.findWords(board, words),
        WhenSorted(UnorderedElementsAre("aba", "aaa", "aaab", "baa", "aaba")));
}
