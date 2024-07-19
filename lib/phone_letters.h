#pragma once

#include <array>
#include <string>
#include <vector>

class Solution {
    using iter = std::vector<std::string>::iterator;
    static constexpr std::array<std::string, 8> letters = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  public:
    std::vector<std::string> letterCombinations(iter begin, iter end) {
        if (begin == end) return {""};
        auto comb = letterCombinations(begin, end - 1);
        std::vector<std::string> acc;
        for (auto c : *(end - 1)) {
            for (auto s : comb) {
                s.push_back(c);
                acc.push_back(s);
            }
        }
        return acc;
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};
        std::vector<std::string> l;
        for (auto c : digits) l.push_back(letters[c - '2']);
        return letterCombinations(l.begin(), l.end());
    }
};
