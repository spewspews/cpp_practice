#include <gtest/gtest.h>

#include <wildcard_match.h>

class WildcardMatchTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(WildcardMatchTests, Weird) {
    ASSERT_TRUE(
        s.isMatch(std::string("abcabczzzde"), std::string("*abc???de*")));
}

TEST_F(WildcardMatchTests, FirstExample) {
    ASSERT_FALSE(s.isMatch(std::string("acdcb"), std::string("a*c?b")));
}

TEST_F(WildcardMatchTests, SecondExample) {
    ASSERT_FALSE(s.isMatch(
        std::string("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"),
        std::string("a*******b")));
}

TEST_F(WildcardMatchTests, JustStar) {
    ASSERT_TRUE(s.isMatch(std::string("acdcb"), std::string("*")));
}

TEST_F(WildcardMatchTests, SimpleCase) {
    ASSERT_FALSE(s.isMatch(std::string("cb"), std::string("?a")));
}

TEST_F(WildcardMatchTests, TooSlow) {
    ASSERT_FALSE(s.isMatch(
        std::string("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabba"
                    "baaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb"),
        std::string("b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a")));
}

TEST_F(WildcardMatchTests, Bad) {
    ASSERT_TRUE(s.isMatch(
        std::string("abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabb"
                    "abbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb"),
        std::string("*b*a*a*b*b*a*b*bbb*baa*bba*b*bb*b*a*aab*a*")));
}
