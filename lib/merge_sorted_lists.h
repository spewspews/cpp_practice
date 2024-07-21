#pragma once

#include <algorithm>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SolutionSlow {
  public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        ListNode *l = nullptr;
        ListNode **tail = &l;
        auto push_back = [&tail](ListNode *n) {
            *tail = n;
            tail = &n->next;
            n->next = nullptr;
        };
        std::erase_if(lists, [](ListNode *n) { return n == nullptr; });
        while (!lists.empty()) {
            auto mi = std::min_element(
                lists.begin(), lists.end(),
                [](ListNode *n1, ListNode *n2) { return n1->val < n2->val; });
            auto next = (*mi)->next;
            push_back(*mi);
            if (next == nullptr) lists.erase(mi);
            else *mi = next;
        }
        return l;
    }
};

class Solution {
  public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        ListNode *l = nullptr;
        ListNode **tail = &l;
        auto push_back = [&tail](ListNode *n) {
            *tail = n;
            tail = &n->next;
            n->next = nullptr;
        };
        std::erase_if(lists, [](ListNode *n) { return n == nullptr; });
        auto cmp = [](ListNode *n1, ListNode *n2) { return n1->val > n2->val; };
        std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)>
            pq(cmp, lists);
        while (!pq.empty()) {
            auto n = pq.top();
            pq.pop();
            if (n->next != nullptr) pq.push(n->next);
            push_back(n);
        }
        return l;
    }
};
