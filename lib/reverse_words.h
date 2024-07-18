#pragma once

#include <vector>

class Solution {
  public:
    void reverseWords(std::vector<char>::iterator begin,
                      std::vector<char>::iterator end, int spaces) {
        if (spaces == 0 || spaces == 1) return;
        auto count = 0;
        auto i = begin;
        for (; i < end; ++i)
            if (*i == ' ' && ++count == spaces / 2) break;
        reverseWords(begin, i + 1, spaces / 2);
        reverseWords(i + 1, end, spaces / 2 + (spaces % 2));
        std::rotate(begin, i + 1, end);
    }

    void reverseWords(std::vector<char> &s) {
        s.push_back(' ');
        auto spaces = 0;
        for (auto i = s.begin(); i < s.end(); ++i)
            if (*i == ' ') ++spaces;
        reverseWords(s.begin(), s.end(), spaces);
        s.pop_back();
    }
};

class SolutionReverse {
  public:
    void reverseWords(std::vector<char> &s) {
        std::reverse(s.begin(), s.end());
        auto prev = s.begin();
        for (auto i = s.begin(); i <= s.end(); ++i) {
            if (i == s.end() || *i == ' ') {
                std::reverse(prev, i);
                prev = i + 1;
            }
        }
    }
};
