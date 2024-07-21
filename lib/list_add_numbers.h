#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        auto n2 = l2;
        for (auto n1 = l1; n1 != nullptr; n1 = n1->next) {
            if (n2 == nullptr) n1->val += carry;
            else n1->val += n2->val + carry;
            if (n1->val > 9) {
                carry = 1;
                n1->val %= 10;
            } else carry = 0;
            if (n1->next == nullptr && n2 != nullptr) {
                n1->next = n2->next;
                n2->next = nullptr;
            }
            if (carry == 1 && n1->next == nullptr) n1->next = new ListNode();
            if (n2 != nullptr) n2 = n2->next;
        }
        return l1;
    }
};
