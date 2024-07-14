#include <gtest/gtest.h>

#include <catch_the_bus.h>

class CatchTheBusTest : public testing::Test {
  protected:
    Solution s;
};

TEST_F(CatchTheBusTest, FirstExample) {
    std::vector<int> buses({10, 20});
    std::vector<int> passengers({2, 17, 18, 19});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 16);
}

TEST_F(CatchTheBusTest, SecondExample) {
    std::vector<int> buses({20, 30, 10});
    std::vector<int> passengers({19, 13, 26, 4, 25, 11, 21});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 20);
}

TEST_F(CatchTheBusTest, WeirdExample) {
    std::vector<int> buses({2});
    std::vector<int> passengers({2});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 1);
}

TEST_F(CatchTheBusTest, AnotherWeirdExample) {
    std::vector<int> buses({3});
    std::vector<int> passengers({2});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 3);
}

TEST_F(CatchTheBusTest, YetAnotherWeirdExample) {
    std::vector<int> buses({3});
    std::vector<int> passengers({3});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 2);
}

TEST_F(CatchTheBusTest, FullExample) {
    std::vector<int> buses({3});
    std::vector<int> passengers({2, 3});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 1);
}

TEST_F(CatchTheBusTest, FullExamplePlus1) {
    std::vector<int> buses({4});
    std::vector<int> passengers({3, 4});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 2);
}

TEST_F(CatchTheBusTest, FullThenEmpty) {
    std::vector<int> buses({4, 5});
    std::vector<int> passengers({3, 4});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 5);
}

TEST_F(CatchTheBusTest, FullThenLotsOfEmpty) {
    std::vector<int> buses({4, 5, 20, 31, 43, 109341});
    std::vector<int> passengers({3, 4});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 109341);
}

TEST_F(CatchTheBusTest, Failing) {
    std::vector<int> buses({2});
    std::vector<int> passengers({2});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 1);
}

TEST_F(CatchTheBusTest, EverybodyIsLate) {
    std::vector<int> buses({5});
    std::vector<int> passengers({7, 8});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 1), 5);
}

TEST_F(CatchTheBusTest, AWeirdOne) {
    // 2,3,5,7,8,9,12,13,18,20
    std::vector<int> buses({18, 8, 3, 12, 9, 2, 7, 13, 20, 5});
    // 2,4,5,8,10,12,13,14,18,19,30,34
    std::vector<int> passengers({13, 10, 8, 4, 12, 14, 18, 19, 5, 2, 30, 34});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 1), 11);
}

TEST_F(CatchTheBusTest, DelayedChoice) {
    std::vector<int> buses({5, 10, 13});
    std::vector<int> passengers({1, 3, 4, 5, 7, 8, 10});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 2), 6);
}

TEST_F(CatchTheBusTest, NotFullBusLeaves) {
    std::vector<int> buses({5});
    std::vector<int> passengers({1, 2, 4, 5});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 5), 3);
}

TEST_F(CatchTheBusTest, AnotherNotFullBusLeaves) {
    std::vector<int> buses({5});
    std::vector<int> passengers({1, 2, 3, 4});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 5), 5);
}

TEST_F(CatchTheBusTest, YetAnotherNotFullBusLeaves) {
    std::vector<int> buses({5});
    std::vector<int> passengers({1, 2, 3, 4, 6});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 5), 5);
}

TEST_F(CatchTheBusTest, SorryYetAnotherNotFullBusLeaves) {
    std::vector<int> buses({5});
    std::vector<int> passengers({1, 2, 3, 5, 6});
    ASSERT_EQ(s.latestTimeCatchTheBus(buses, passengers, 5), 4);
}
