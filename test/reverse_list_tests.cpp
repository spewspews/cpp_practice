#include <gtest/gtest.h>

#include <reverse_list.h>

class ReverseLinkedListTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Solution s;
};

TEST_F(ReverseLinkedListTests, FirstExample) {
    std::vector<ListNode> nodes(3);
    nodes[0].val = 1;
    nodes[0].next = &nodes[1];
    nodes[1].val = 2;
    nodes[1].next = &nodes[2];
    nodes[2].val = 3;
    auto r = s.reverseList(&nodes[0]);
    ASSERT_EQ(r->val, 3);
    r = r->next;
    ASSERT_EQ(r->val, 2);
    r = r->next;
    ASSERT_EQ(r->val, 1);
    r = r->next;
    ASSERT_EQ(r, nullptr);
}
