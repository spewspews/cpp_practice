#pragma once

#include <algorithm>
#include <map>
#include <vector>

class Solution {
  public:
    int maxIntersectionCount(std::vector<int> &y) {
        if (y.size() <= 1) return -1;
        std::map<int, int> sweep_totals;
        for (auto i = y.begin(); i + 1 < y.end(); ++i) {
            auto e1 = *i * 2;
            auto e2 = *(i + 1) * 2;
            int dir;
            if (i + 2 == y.end()) dir = 0;
            else dir = e1 < e2 ? 1 : -1;
            e2 -= dir;
            ++sweep_totals[std::min(e1, e2)];
            --sweep_totals[std::max(e1, e2) + 1];
        }
        int max = 0;
        int count = 0;
        for (auto i = sweep_totals.begin(); i != sweep_totals.end(); ++i) {
            count += i->second;
            max = std::max(max, count);
        }
        return max;
    }
};
