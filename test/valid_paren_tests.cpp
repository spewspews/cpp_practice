#include <gtest/gtest.h>

#include <valid_paren.h>

class ValidParenTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(ValidParenTests, FirstExample) { ASSERT_TRUE(s.isValid("()")); }
