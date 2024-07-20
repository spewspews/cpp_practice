#pragma once

#include <stdexcept>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class SolutionSlow {
  public:
    int min(TreeNode *root) {
        if (root == nullptr)
            throw std::runtime_error("Only call min on non nullptrs");
        if (root->left == nullptr) return root->val;
        return min(root->left);
    }

    int max(TreeNode *root) {
        if (root == nullptr)
            throw std::runtime_error("Only call min on non nullptrs");
        if (root->right == nullptr) return root->val;
        return min(root->right);
    }

    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;
        if (root->left != nullptr && root->val <= max(root->left)) return false;
        if (root->right != nullptr && root->val >= min(root->right))
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};

class Solution {
  public:
    bool inOrder(TreeNode *root, std::optional<int> &prev) {
        if (root == nullptr) return true;
        if (!inOrder(root->left, prev)) return false;
        if (prev.has_value() && root->val <= prev) return false;
        prev = root->val;
        return inOrder(root->right, prev);
    }

    bool isValidBST(TreeNode *root) {
        std::optional<int> prev;
        return inOrder(root, prev);
    }
};
