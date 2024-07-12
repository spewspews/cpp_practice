#pragma once

#include <iostream>

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

class Solution {
public:
  /**
   * Adds the two digits of an int < 100 together until one digit remains.
   *
   * @param i, must be less than 100.
   */
  int digit_sum_of_int(int i) {
    if (i >= 100) throw std::runtime_error("Bad input");
    while (i >= 10) i = i % 10 + i / 10;
    return i;
  }

  int digit_sum_of_vector(std::vector<int> &digits) {
    int sum = 0;
    for (auto i = digits.begin(); i < digits.end(); ++i) {
      sum += *i;
      sum = digit_sum_of_int(sum);
    }
    return sum;
  }

  std::string largestMultipleOfThreeWorse(std::vector<int> &digits) {
    auto sum = digit_sum_of_vector(digits);
    std::sort(digits.begin(), digits.end());
    switch (sum % 3) {
    case 0:
      break;
    case 1: {
      auto i = digits.begin();
      for (; i < digits.end(); ++i) {
        if (*i == 1 || *i == 4 || *i == 7) break;
      }
      if (i != digits.end()) {
        digits.erase(i);
        break;
      }
      i = digits.begin();
      auto erased = 0;
      for (; i < digits.end();) {
        if (*i == 2 || *i == 5 || *i == 8) {
          i = digits.erase(i);
          if (++erased == 2) break;
        } else ++i;
      }
      if (erased < 2) return "";
    } break;
    case 2: {
      auto i = digits.begin();
      for (; i < digits.end(); ++i) {
        if (*i == 2 || *i == 5 || *i == 8) break;
      }
      if (i != digits.end()) {
        digits.erase(i);
        break;
      }
      i = digits.begin();
      auto erased = 0;
      for (; i < digits.end();) {
        if (*i == 1 || *i == 4 || *i == 7) {
          i = digits.erase(i);
          if (++erased == 2) break;
        } else ++i;
      }
      if (erased < 2) return "";
    } break;
    }
    if (digits.size() == 0) return "";
    constexpr auto pred = [](int i) { return i == 0; };
    if (std::all_of(digits.begin(), digits.end(), pred)) return "0";
    std::string s;
    for (auto i = digits.rbegin(); i < digits.rend(); ++i)
      s.push_back(*i + '0');
    return s;
  }

  std::string largestMultipleOfThree(std::vector<int> &digits) {
    std::vector<int> digit_count(10);
    unsigned long long sum = 0;
    for (auto d : digits) {
      ++digit_count[d];
      sum += d;
    }
    std::vector<int> l1 = {1, 4, 7, 2, 5, 8};
    std::vector<int> l2 = {2, 5, 8, 1, 4, 7};
    while (sum % 3 != 0) {
      for (auto &n : sum % 3 == 1 ? l1 : l2) {
        if (digit_count[n] > 0) {
          --digit_count[n];
          sum -= n;
          break;
        }
      }
    }
    std::string s;
    for (int i = 9; i >= 0; --i) {
      while (digit_count[i]-- > 0) s.push_back(i + '0');
    }
    if (s.size() == 0) return "";
    if (s.front() == '0') return "0";
    return s;
  }
};
