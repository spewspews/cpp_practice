#include <gtest/gtest.h>

#include <trie.h>

class TrieTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Trie t;
};

TEST_F(TrieTests, FindInsertedWord) {
    t.insert("child");
    ASSERT_TRUE(t.search("child"));
    ASSERT_FALSE(t.search("foo"));
    ASSERT_FALSE(t.search("chi"));
    ASSERT_TRUE(t.startsWith("chi"));
}

TEST_F(TrieTests, Apple) {
    t.insert("apple");
    ASSERT_TRUE(t.search("apple"));
    ASSERT_FALSE(t.search("app"));
    ASSERT_TRUE(t.startsWith("app"));
    t.insert("app");
    ASSERT_TRUE(t.search("app"));
}
