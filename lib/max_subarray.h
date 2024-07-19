#pragma once

#include <limits>
#include <map>
#include <queue>
#include <vector>

class Solution {
  public:
    using iter = std::vector<int>::iterator;
    int maxSubArray(std::vector<int> &nums) {
        auto max = std::numeric_limits<int>::min();
        auto cur = 0;
        for (auto n : nums) {
            cur = std::max(n, cur + n);
            max = std::max(max, cur);
        }
        return max;
    }

    int maxSubArrayBruteForce(std::vector<int> &nums) {
        auto max = std::numeric_limits<int>::min();
        std::queue<std::tuple<iter, iter, int>> q;
        std::map<iter, std::vector<std::pair<iter, int>>> calculated;
        for (auto i = nums.begin(); i < nums.end(); ++i) {
            q.emplace(i, i + 1, *i);
            calculated[i].emplace_back(i + 1, *i);
            max = std::max(max, *i);
        }
        while (!q.empty()) {
            auto [b, e, sum] = q.front();
            q.pop();
            if (e < nums.end()) {
                for (auto [i, sumi] : calculated[e]) {
                    auto newSum = sum + sumi;
                    q.emplace(b, i, newSum);
                    max = std::max(max, newSum);
                }
            }
        }
        return max;
    }
};
