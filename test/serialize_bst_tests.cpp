#include <gtest/gtest.h>

#include <serialize_bst.h>

class SerializeBSTTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}

    Codec c;
};

TEST_F(SerializeBSTTests, FirstExample) {
    std::vector<TreeNode> nodes;
    for (auto i : {2, 1, 3, 4}) nodes.emplace_back(i);
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[2].left = &nodes[3];
    ASSERT_EQ(c.serialize(&nodes[0]), "2|1|3|4|");
}

TEST_F(SerializeBSTTests, Deserialize) {
    auto n = c.deserialize("2|1|3|4|");
    ASSERT_NE(n, nullptr);
    ASSERT_EQ(c.serialize(n), "2|1|3|4|");
}
