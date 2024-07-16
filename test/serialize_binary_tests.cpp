#include <gtest/gtest.h>

#include <serialize_binary.h>

class SerializeBinaryTests : public testing::Test {
  protected:
    void SetUp() {}
    void TearDown() {}
    Codec c;
};

TEST_F(SerializeBinaryTests, FirstExample) {
    std::vector<TreeNode *> nodes;
    for (auto i : {2 + ((0xff & '\x80') << 16), 1, 3, 4})
        nodes.push_back(new TreeNode(i));
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[2]->left = nodes[3];
    std::string s({'\3', '\2', '\0', '\x80', '\1', '\1', '\0', '\0', '\1', '\3',
                   '\1', '\4', '\0', '\0', '\0'});
    ASSERT_EQ(c.serialize(nodes[0]), s);
    delete nodes[0];
}

TEST_F(SerializeBinaryTests, SecondExample) {
    std::vector<TreeNode *> nodes;
    for (auto i : {2 + ((0xff & '\x80') << 24), 1, 3, 4})
        nodes.push_back(new TreeNode(i));
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[2]->left = nodes[3];
    std::string s({'\4', '\2', '\0', '\0', '\x80', '\1', '\1', '\0', '\0', '\1',
                   '\3', '\1', '\4', '\0', '\0', '\0'});
    ASSERT_EQ(c.serialize(nodes[0]), s);
    delete nodes[0];
}

TEST_F(SerializeBinaryTests, FirstDeserializeExample) {
    std::string s({'\3', '\2', '\0', '\x80', '\1', '\1', '\0', '\0', '\1', '\3',
                   '\1', '\4', '\0', '\0', '\0'});
    auto n = c.deserialize(s);
    ASSERT_NE(n, nullptr);
    ASSERT_EQ(c.serialize(n), s);
    delete n;
}

TEST_F(SerializeBinaryTests, SecondDeserializeExample) {
    std::string s({'\4', '\2', '\0', '\0', '\x80', '\1', '\1', '\0', '\0', '\1',
                   '\3', '\1', '\4', '\0', '\0', '\0'});
    auto n = c.deserialize(s);
    ASSERT_NE(n, nullptr);
    ASSERT_EQ(c.serialize(n), s);
    delete n;
}
