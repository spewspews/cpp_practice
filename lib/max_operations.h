#pragma once

#include <algorithm>
#include <vector>

class Solution {
    using iter = std::vector<int>::iterator;
    std::vector<std::vector<int>> memo;

  public:
    int maxOps(iter b, iter e, iter begin, int val) {
        if (b == e || b + 1 == e) return 0;
        if (auto m = memo[b - begin][e - 1 - begin]; m != -1) return m;
        int max = 0;
        if (*b + *(b + 1) == val)
            max = std::max(max, 1 + maxOps(b + 2, e, begin, val));
        if (*(e - 1) + *(e - 2) == val)
            max = std::max(max, 1 + maxOps(b, e - 2, begin, val));
        if (*b + *(e - 1) == val)
            max = std::max(max, 1 + maxOps(b + 1, e - 1, begin, val));
        memo[b - begin][e - 1 - begin] = max;
        return max;
    }

    int maxOperations(std::vector<int> &nums) {
        if (nums.size() < 2) return 0;
        memo = std::vector(nums.size(), std::vector(nums.size(), -1));
        auto b = nums.begin();
        auto e = nums.end();
        return 1 + std::max({maxOps(b + 2, e, b, *b + *(b + 1)),
                             maxOps(b, e - 2, b, *(e - 1) + *(e - 2)),
                             maxOps(b + 1, e - 1, b, *b + *(e - 1))});
    }
};
