#pragma once

#include <limits>
#include <vector>

class Solution {
  public:
    int maxProfit(std::vector<int> &prices) {
        auto min = std::numeric_limits<int>::max();
        auto profit = 0;
        for (auto p : prices) {
            min = std::min(min, p);
            profit = std::max(profit, p - min);
        }
        return profit;
    }
};
