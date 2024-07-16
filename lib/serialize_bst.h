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

  public:
    void serialize(std::ostream &s, TreeNode *root) {
        if (root == nullptr) return;
        s << root->val << '|';
        serialize(s, root->left);
        serialize(s, root->right);
    }

    std::string serialize(TreeNode *root) {
        std::ostringstream oss;
        serialize(oss, root);
        return oss.str();
    }

    TreeNode *deserialize(std::vector<int>::iterator begin,
                          std::vector<int>::iterator end) {
        if (begin == end) return nullptr;
        auto n = newNode(*begin);
        auto i = begin + 1;
        for (; i < end; ++i)
            if (*i > *begin) break;
        n->left = deserialize(begin + 1, i);
        n->right = deserialize(i, end);
        return n;
    }

    TreeNode *deserializeOld(std::string data) {
        std::istringstream ss(data);
        std::vector<int> vals;
        for (;;) {
            auto [eof, i] = lex(ss);
            if (eof) break;
            vals.push_back(i);
        }
        return deserialize(vals.begin(), vals.end());
    }

    TreeNode *newNode(int i) {
        nodes.emplace_back(i);
        return &nodes.back();
    }

    std::pair<bool, int> lex(std::istream &s) {
        int i;
        char c;
        s >> i >> c;
        if (s.eof()) return {true, 0};
        if (c != '|') throw std::runtime_error("Bad string");
        return {false, i};
    }

    TreeNode *deserialize(std::string data) {
        std::istringstream ss(data);
        TreeNode *root = nullptr;
        for (;;) {
            auto [eof, i] = lex(ss);
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
