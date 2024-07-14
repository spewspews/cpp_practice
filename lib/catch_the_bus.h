#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

// Problem 2332.
// https://leetcode.com/problems/the-latest-time-to-catch-a-bus/description/
//
// Lessons learned: If a simulation seems performant, then do the simulation
// and see what the results are. This involved writing essentially the
// same code as below and just printing out the `slot` as the earliest
// possible time. It was almost completely correct.
//
// The only change was adding the line
//     `if (np < capacity && prev < b) slot = b;

class Solution {
  public:
    int latestTimeCatchTheBus(std::vector<int> &buses,
                              std::vector<int> &passengers, int capacity) {
        std::sort(buses.begin(), buses.end());
        std::sort(passengers.begin(), passengers.end());
        auto prev = -1;
        auto slot = -1;
        auto pi = passengers.begin();
        auto latestTime = 1;
        for (auto b : buses) {
            auto np = 0;
            while (pi != passengers.end() && *pi <= b) {
                if (prev < *pi - 1) slot = *pi - 1;
                prev = *pi;
                ++pi;
                if (++np == capacity) break;
            }
            if (np < capacity && prev < b) slot = b;
            latestTime = slot;
        }
        return latestTime;
    }
};
