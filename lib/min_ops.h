#pragma once

#include <cmath>
#include <queue>
#include <set>
#include <utility>

class Solution {
  std::queue<std::pair<int, int>> q;
  std::set<int> reached;
  void enqueue(int x, int ops) {
    if (reached.find(x) != reached.end()) return;
    q.push(std::pair(x, ops));
    reached.insert(x);
  }

public:
  int minimumOperationsToMakeEqual(int x, int y) {
    if (x <= y) return y - x;
    enqueue(x, 0);
    while (!q.empty()) {
      auto [x, ops] = q.front();
      q.pop();
      if (x == y) return ops;
      enqueue(x + 1, ops + 1);
      if (x < y) continue;
      if (x % 11 == 0) enqueue(x / 11, ops + 1);
      if (x % 5 == 0) enqueue(x / 5, ops + 1);
      enqueue(x - 1, ops + 1);
    }
    return -1;
  }
};
