#pragma once

#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionMemoryUsage {
  public:
    std::unordered_set<ListNode *> nodes;

    bool hasCycle(ListNode *head) {
        nodes.clear();
        for (auto n = head; n != nullptr; n = n->next) {
            if (nodes.contains(n)) return true;
            nodes.insert(n);
        }
        return false;
    }
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
