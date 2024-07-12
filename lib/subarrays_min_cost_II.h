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
        auto findMax = [&heap, &max]() -> int {
            auto i = 0;
            for (auto it = heap.begin(); it != heap.end(); ++it) {
                if (it == max) return i;
                ++i;
            }
            return -1;
        };
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
        for (auto i = nums.begin() + 2 + dist; i < nums.end(); ++i) {
            curCost += *(i - dist) - *(i - dist - 1);
            q.push(heap.insert(*i));
            if (*i < *max) {
                curCost += *i - *max;
                max = std::prev(max);
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
        for (auto i = nums.end() - dist; i < nums.end() - k + 2; ++i) {
            curCost += *i - *(i - 1);
            if (q.empty()) break;
            auto eject = q.front();
            if (lessThanMax(eject)) {
                curCost -= *eject;
                if (std::next(max) != heap.end()) {
                    max = std::next(max);
                    curCost += *max;
                }
            }
            heap.erase(eject);
            q.pop();
            minCost = std::min(minCost, curCost);
        }
        return minCost;
    }
};
