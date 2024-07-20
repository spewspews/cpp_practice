#pragma once

#include <vector>

class Solution {
  public:
    template <class V>
    void qSort(std::span<V> nums) {
        if (nums.size() == 0) return;
        auto &p = nums.front();
        auto i = nums.begin() + 1;
        for (; i < nums.end(); ++i)
            if (*i >= p) break;
        auto big = i;
        for (; i < nums.end(); ++i) {
            if (p <= *i) continue;
            std::swap(*i, *big);
            ++big;
        }
        std::swap(p, *(big - 1));
        qSort(std::span(nums.begin(), big - 1));
        qSort(std::span(big, nums.end()));
    }

    void sortColors(std::vector<int> &nums) { qSort<int>(nums); }
};
