#pragma once

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SolutionAllocating {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        std::vector<int> s1;
        std::vector<int> s2;
        for (auto n = l1; n != nullptr; n = n->next) s1.push_back(n->val);
        for (auto n = l2; n != nullptr; n = n->next) s2.push_back(n->val);
        auto carry = 0;
        ListNode *l = nullptr;
        for (;; s1.pop_back()) {
            if (s1.empty() && !s2.empty()) std::swap(s1, s2);
            if (s1.empty() && carry == 1) s1.push_back(0);
            if (s1.empty()) break;
            auto v = s1.back();
            if (s2.empty()) v += carry;
            else v += s2.back() + carry;
            if (v > 9) {
                v %= 10;
                carry = 1;
            } else carry = 0;
            auto n = new ListNode(v);
            n->next = l;
            l = n;
            if (!s2.empty()) s2.pop_back();
        }
        return l;
    }
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        std::vector<int> s1;
        std::vector<int> s2;
        ListNode *free = nullptr;
        auto pushAll = [&free](ListNode *l, std::vector<int> &s) {
            ListNode *next = nullptr;
            for (auto n = l; n != nullptr; n = next) {
                s.push_back(n->val);
                next = n->next;
                n->next = free;
                free = n;
            }
        };
        // This could equally well be new ListNode(val);
        auto allocNode = [&free](int val) -> ListNode * {
            auto n = free;
            free = free->next;
            n->val = val;
            n->next = nullptr;
            return n;
        };
        pushAll(l1, s1);
        pushAll(l2, s2);
        auto carry = 0;
        ListNode *l = nullptr;
        for (;; s1.pop_back()) {
            if (s1.empty() && !s2.empty()) std::swap(s1, s2);
            if (s1.empty() && carry == 1) s1.push_back(0);
            if (s1.empty()) break;
            auto v = s1.back();
            if (s2.empty()) v += carry;
            else v += s2.back() + carry;
            if (v > 9) {
                v %= 10;
                carry = 1;
            } else carry = 0;
            auto n = allocNode(v);
            n->next = l;
            l = n;
            if (!s2.empty()) s2.pop_back();
        }
        return l;
    }
};
