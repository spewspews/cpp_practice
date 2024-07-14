#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// This is LeetCode 2246:
// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

// Lessons Learned: Initially wanted to try to do this without
// constructing an explicit data structure, thinking there may
// some trick to it. But there's no way to sort the vector without
// losing all the parent index information.

// Once I implemented the tree it was easy.

class Solution {
    class Node {
      public:
        Node() : val('\0'), maxPath(-1) {}
        char val;
        int maxPath;
        std::vector<Node *> child;

        int calcLongestDown() {
            // The following check is only useful if this
            // is called twice.
            if (maxPath != -1) return maxPath;
            maxPath = 1;
            if (child.empty()) return maxPath;
            for (auto c : child) {
                auto l = c->calcLongestDown();
                if (c->val != val) maxPath = std::max(maxPath, l + 1);
            }
            return maxPath;
        }

        void mergePaths() {
            if (child.empty()) return;
            int mcp = -1;
            auto ci = child.begin();
            for (; ci + 1 < child.end(); ++ci) {
                if ((*ci)->val == val) continue;
                if (mcp == -1) {
                    mcp = (*ci)->maxPath;
                    continue;
                }
                maxPath = std::max(maxPath, (*ci)->maxPath + mcp + 1);
                mcp = std::max(mcp, (*ci)->maxPath);
            }
            if ((*ci)->val != val && mcp != -1)
                maxPath = std::max(maxPath, (*ci)->maxPath + mcp + 1);
            for (auto c : child) c->mergePaths();
        }
    };

  public:
    int longestPath(std::vector<int> &parent, std::string s) {
        std::vector<Node> nodes(parent.size());
        nodes[0].val = s[0];
        for (decltype(parent.size()) i = 1; i < parent.size(); ++i) {
            nodes[i].val = s[i];
            nodes[parent[i]].child.push_back(&nodes[i]);
        }
        nodes[0].calcLongestDown();
        nodes[0].mergePaths();
        auto maxn = std::max_element(nodes.begin(), nodes.end(),
                                     [](const Node &n1, const Node &n2) {
                                         return n1.maxPath < n2.maxPath;
                                     });
        return maxn->maxPath;
    }
};
