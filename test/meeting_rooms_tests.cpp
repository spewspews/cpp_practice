#include <gtest/gtest.h>

#include <meeting_rooms.h>

class MeetingRoomsTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(MeetingRoomsTest, OverlapReturns2) {
  {
    std::vector<std::vector<int>> v({{0, 30}, {5, 10}, {15, 20}});
    ASSERT_EQ(s.minMeetingRooms(v), 2);
  }
}

TEST_F(MeetingRoomsTest, NoOverlapReturns1) {
  {
    std::vector<std::vector<int>> v({{7, 10}, {2, 4}});
    ASSERT_EQ(s.minMeetingRooms(v), 1);
  }
}

TEST_F(MeetingRoomsTest, EdgesReturns1) {
  {
    std::vector<std::vector<int>> v({{13, 15}, {1, 13}});
    ASSERT_EQ(s.minMeetingRooms(v), 1);
  }
}
