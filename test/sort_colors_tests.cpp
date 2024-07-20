#include <gtest/gtest.h>

#include <sort_colors.h>

class SortColorsTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(SortColorsTests, FirstExample) {
    std::vector v({2, 0, 2, 1, 1, 0});
    s.sortColors(v);
    ASSERT_EQ(v, std::vector({0, 0, 1, 1, 2, 2}));
}
