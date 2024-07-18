#pragma once

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::map<int, decltype(nums.size())> m;
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i)
            m.emplace(nums[i], i);
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
            if (auto j = m.find(target - nums[i]);
                j != m.end() && i != j->second)
                return {(int)i, (int)j->second};
        }
        return {};
    }
};
