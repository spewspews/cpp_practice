#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>

class Solution {
  public:
    long long minimumCost(std::vector<int> &nums, int k, int dist) {
        std::multiset<int> heap;
        std::queue<std::multiset<int>::iterator> q;
        long long minCost = nums[0] + nums[1];
        for (auto i = nums.begin() + 2; i < nums.begin() + 2 + dist; ++i)
            q.push(heap.insert(*i));
        auto it = heap.begin();
        for (auto i = 0; i < k - 2; ++i) minCost += *it++;
        auto max = std::prev(it);
        auto curCost = minCost;
        auto lessThanMax = [&heap, &max](auto it) -> bool {
            if (it == max) return true;
            if (*it < *max) return true;
            if (*it > *max) return false;
            auto v = *it;
            while (it != heap.end() && *it++ == v) {
                if (it == max) return true;
            }
            return false;
        };
        for (auto i = nums.begin() + 2; i < nums.end() - k + 2; ++i) {
            curCost += *i - *(i - 1);
            if (i < nums.end() - dist) {
                q.push(heap.insert(*(i + dist)));
                if (*(i + dist) < *max) {
                    curCost += *(i + dist) - *max;
                    max = std::prev(max);
                }
            }
            auto eject = q.front();
            if (lessThanMax(eject)) {
                curCost -= *eject;
                max = std::next(max);
                curCost += *max;
            }
            heap.erase(eject);
            q.pop();
            minCost = std::min(minCost, curCost);
        }
        return minCost;
    }
};
