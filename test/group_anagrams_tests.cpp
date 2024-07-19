#include <gtest/gtest.h>

#include <group_anagrams.h>

class GroupAnagramsTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(GroupAnagramsTests, FirstExample) {
    std::vector<std::string> v({"eat", "tea", "tan", "ate", "nat", "bat"});
    ASSERT_EQ(s.groupAnagrams(v),
              std::vector<std::vector<std::string>>(
                  {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}}));
}
