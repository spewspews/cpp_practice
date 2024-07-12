#include <gtest/gtest.h>

#include <rank_teams.h>

class RankTeamsTests : public testing::Test {
  protected:
    Solution s;
};

TEST_F(RankTeamsTests, OneVoteReturnsString) {
    {
        std::vector<std::string> v({"ABCDE"});
        ASSERT_EQ(s.rankTeams(v), "ABCDE");
    }
    {
        std::vector<std::string> v({"DBAXVC"});
        ASSERT_EQ(s.rankTeams(v), "DBAXVC");
    }
    {
        std::vector<std::string> v({"ZMNAGUEDSJYLBOPHRQICWFXTVK"});
        ASSERT_EQ(s.rankTeams(v), "ZMNAGUEDSJYLBOPHRQICWFXTVK");
    }
}

TEST_F(RankTeamsTests, TestCase1) {
    std::vector<std::string> v({"ABC", "ACB", "ABC", "ACB", "ACB"});
    ASSERT_EQ(s.rankTeams(v), "ACB");
}

TEST_F(RankTeamsTests, TestCase2) {
    std::vector<std::string> v({"WXYZ", "XYZW"});
    //    v.push_back("WXYZ");
    //    v.push_back("XYZW");
    ASSERT_EQ(s.rankTeams(v), "XWYZ");
}
