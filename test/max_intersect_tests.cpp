#include <gtest/gtest.h>

#include <max_intersect.h>

class MaxIntersectTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(MaxIntersectTest, NoLineReturnsNegative) {
  {
    std::vector<int> v;
    ASSERT_EQ(s.maxIntersectionCount(v), -1);
  }
  {
    std::vector<int> v({1});
    ASSERT_EQ(s.maxIntersectionCount(v), -1);
  }
}

TEST_F(MaxIntersectTest, OneLineReturnsOne) {
  {
    std::vector<int> v{1, 2};
    ASSERT_EQ(s.maxIntersectionCount(v), 1);
  }
}

TEST_F(MaxIntersectTest, ZigZagReturnsTwo) {
  {
    std::vector<int> v{1, 2, 1};
    ASSERT_EQ(s.maxIntersectionCount(v), 2);
  }
}

TEST_F(MaxIntersectTest, ZigZagReturnsUpperFour) {
  {
    std::vector<int> v{1, 2, 1, 3, 2, 3, 2};
    ASSERT_EQ(s.maxIntersectionCount(v), 4);
  }
}

TEST_F(MaxIntersectTest, WeirdGraphHas9) {
  {
    std::vector<int> v{2, 3, 4, 3, 4, 1, 4, 1, 2, 3, 4, 2, 1, 2, 1, 3, 2};
    ASSERT_EQ(s.maxIntersectionCount(v), 9);
  }
}

TEST_F(MaxIntersectTest, DoubleZigZagReturnsThree) {
  {
    std::vector<int> v{1, 2, 1, 2};
    ASSERT_EQ(s.maxIntersectionCount(v), 3);
  }
}
