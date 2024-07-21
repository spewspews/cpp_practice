#pragma once

#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> out;
        std::queue<TreeNode *> q;
        q.push(root);
        for (;;) {
            std::queue<TreeNode *> newq;
            std::vector<int> vals;
            for (; !q.empty(); q.pop()) {
                auto n = q.front();
                if (n == nullptr) continue;
                vals.push_back(n->val);
                newq.push(n->left);
                newq.push(n->right);
            }
            if (vals.empty()) break;
            out.push_back(vals);
            q = std::move(newq);
        }
        return out;
    }
};
