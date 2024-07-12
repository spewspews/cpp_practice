#pragma once

#include <iostream>
#include <vector>

class Solution {
  public:
    int largestCombinationSlow(std::vector<int> &c) {
        int acc = -1;
        int count = 0;
        auto i = c.begin();
        for (; i < c.end(); ++i) {
            if (*i == -1) continue;
            acc &= *i;
            if (acc == 0) break;
            ++count;
        }
        if (i == c.end()) return count;
        auto max = 0;
        for (auto i = c.begin(); i < c.end(); ++i) {
            if (*i == -1) return max;
            auto t = *i;
            *i = -1;
            max = std::max(max, largestCombinationSlow(c));
            *i = t;
        }
        return max;
    }

    int largestCombination(std::vector<int> &candidates) {
        std::vector<int> bitcount(32);
        for (auto i = candidates.begin(); i < candidates.end(); ++i) {
            auto c = *i;
            for (auto it = bitcount.begin(); it < bitcount.end(); ++it) {
                *it += c & 1;
                c >>= 1;
            }
        }
        int max = 0;
        for (auto it = bitcount.begin(); it < bitcount.end(); ++it)
            max = std::max(max, *it);
        return max;
    }
};
