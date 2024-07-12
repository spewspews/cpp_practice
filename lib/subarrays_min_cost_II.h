#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>

class Solution {
  public:
    long long minimumCostSlow(std::vector<int> &nums, int k, int dist) {
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

    long long minimumCost(std::vector<int> &nums, int k, int dist) {
        std::multiset<int> heap_low, heap_high;
        long long minCost = nums[0] + nums[1];
        for (auto i = nums.begin() + 2; i < nums.begin() + 2 + dist; ++i)
            heap_low.insert(*i);
        while (heap_low.size() > k - 2) {
            auto max = std::prev(heap_low.end());
            heap_high.insert(*max);
            heap_low.erase(max);
        }
        for (auto i = heap_low.begin(); i != heap_low.end(); ++i) minCost += *i;
        auto curCost = minCost;
        for (auto i = nums.begin() + 2; i < nums.end() - k + 2; ++i) {
            curCost += *i - *(i - 1);
            if (i < nums.end() - dist) {
                auto max = std::prev(heap_low.end());
                if (*(i + dist) < *max) {
                    heap_low.insert(*(i + dist));
                    curCost += *(i + dist) - *max;
                    heap_high.insert(*max);
                    heap_low.erase(max);
                } else heap_high.insert(*(i + dist));
            }
            if (heap_high.empty()) break;
            auto max = std::prev(heap_low.end());
            if (*i <= *max) {
                curCost += *heap_high.begin() - *i;
                heap_low.erase(heap_low.find(*i));
                heap_low.insert(*heap_high.begin());
                heap_high.erase(heap_high.begin());
            } else heap_high.erase(heap_high.find(*i));
            minCost = std::min(minCost, curCost);
        }
        return minCost;
    }
};
