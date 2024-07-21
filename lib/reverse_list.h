#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SolutionRecursive {
  public:
    ListNode *reverseList(ListNode *head, ListNode *&newHead) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) {
            std::cout << "New head val=" << head->val << std::endl;
            newHead = head;
            return head;
        }
        auto n = reverseList(head->next, newHead);
        std::cout << "Got a node back its val=" << n->val << std::endl;
        std::cout << "Head is val=" << head->val << std::endl;
        n->next = head;
        head->next = nullptr;
        return head;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *ret;
        reverseList(head, ret);
        return ret;
    }
};

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *next;
        for (auto n = head; n != nullptr; n = next) {
            next = n->next;
            n->next = prev;
            prev = n;
        }
        return prev;
    }
};
