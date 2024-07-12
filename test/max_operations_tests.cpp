#include <gtest/gtest.h>

#include <max_operations.h>

class MaxOperationsTest : public testing::Test {
  protected:
    Solution s;
};

TEST_F(MaxOperationsTest, NoOperations) {
    {
        std::vector<int> v({1});
        ASSERT_EQ(s.maxOperations(v), 0);
    }
}

TEST_F(MaxOperationsTest, OneOperation) {
    {
        std::vector<int> v({1, 3});
        ASSERT_EQ(s.maxOperations(v), 1);
    }
}

TEST_F(MaxOperationsTest, ThreeOperations) {
    {
        std::vector<int> v({3, 2, 1, 2, 3, 4});
        ASSERT_EQ(s.maxOperations(v), 3);
    }
}

TEST_F(MaxOperationsTest, TwoOperations) {
    {
        std::vector<int> v({1, 9, 7, 3, 2, 7, 4, 12, 2, 6});
        ASSERT_EQ(s.maxOperations(v), 2);
    }
}
