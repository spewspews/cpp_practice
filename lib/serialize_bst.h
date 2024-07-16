#pragma once

#include <list>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    std::list<TreeNode> nodes;

    std::pair<bool, int> readInt(std::istream &s) {
        char c;
        int v = 0;
        for (decltype(sizeof(v)) i = 0; i < sizeof(v); ++i) {
            s.get(c);
            if (s.eof()) return {true, 0};
            v |= ((255 & c) << (8 * i));
        }
        return {false, v};
    }

    void writeInt(std::ostream &s, int v) {
        for (decltype(sizeof(v)) i = 0; i < sizeof(v); ++i) {
            s.put(v);
            v >>= 8;
        }
    }

  public:
    void serialize(std::ostream &s, TreeNode *root) {
        if (root == nullptr) return;
        writeInt(s, root->val);
        serialize(s, root->left);
        serialize(s, root->right);
    }

    std::string serialize(TreeNode *root) {
        std::ostringstream oss;
        serialize(oss, root);
        return oss.str();
    }

    TreeNode *newNode(int i) {
        nodes.emplace_back(i);
        return &nodes.back();
    }

    TreeNode *deserialize(std::string data) {
        std::istringstream ss(data);
        TreeNode *root = nullptr;
        for (;;) {
            auto [eof, i] = readInt(ss);
            if (eof) break;
            auto n = &root;
            for (;;) {
                if (*n == nullptr) {
                    *n = newNode(i);
                    break;
                }
                if (i < (*n)->val) n = &(*n)->left;
                else n = &(*n)->right;
            }
        }
        return root;
    }
};
