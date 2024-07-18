#pragma once

#include <unordered_map>

class Solution {
  public:
    auto twoSum(std::vector<int> &nums,
                int target) -> std::vector<decltype(nums.size())> {
        std::unordered_map<int, decltype(nums.size())> m;
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
            if (auto j = m.find(target - nums[i]); j != m.end())
                return {j->second, i};
            m.emplace(nums[i], i);
        }
        return {};
    }
};

class SolutionInt {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::map<int, decltype(nums.size())> m;
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
            if (auto j = m.find(target - nums[i]); j != m.end())
                return {(int)j->second, (int)i};
            m.emplace(nums[i], i);
        }
        return {};
    }
};
