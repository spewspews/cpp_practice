#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <phone_letters.h>

class PhoneLetterCombinationsTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

using testing::UnorderedElementsAre;
using testing::WhenSorted;

TEST_F(PhoneLetterCombinationsTests, FirstExample) {
    ASSERT_THAT(s.letterCombinations("23"),
                WhenSorted(UnorderedElementsAre("ad", "ae", "af", "bd", "be",
                                                "bf", "cd", "ce", "cf")));
}
