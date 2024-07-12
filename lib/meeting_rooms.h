#pragma once

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
  int minMeetingRooms1(std::vector<std::vector<int>> &intervals) {
    std::map<int, int> changes;
    for (auto i : intervals) {
      ++changes[i[0]];
      --changes[i[1]];
    }
    int minRooms = 0, count = 0;
    for (auto [_, c] : changes) {
      count += c;
      minRooms = std::max(minRooms, count);
    }
    return minRooms;
  }

  int minMeetingRooms(std::vector<std::vector<int>> &intervals) {
    std::vector<std::tuple<int, int8_t>> changes;
    for (auto i : intervals) {
      changes.emplace_back(i[0], 1);
      changes.emplace_back(i[1], -1);
    }
    std::sort(changes.begin(), changes.end());
    int minRooms = 0, count = 0;
    for (auto [_, c] : changes) {
      count += c;
      minRooms = std::max(minRooms, count);
    }
    return minRooms;
  }
};
