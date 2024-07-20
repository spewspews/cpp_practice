#pragma once

#include <array>
#include <queue>
#include <string>
#include <vector>

class Solution {
    static constexpr std::array<std::string, 8> letters = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  public:
    std::vector<std::string> letterCombinations(const std::string_view s) {
        if (s.empty()) return {""};
        auto comb = letterCombinations(s.substr(0, s.size() - 1));
        std::vector<std::string> acc;
        for (auto c : letters[s.back() - '2']) {
            for (auto s : comb) {
                s.push_back(c);
                acc.push_back(std::move(s));
            }
        }
        return acc;
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};
        return letterCombinations(std::string_view(digits));
    }

    std::vector<std::string> letterCombinationsBFS(std::string digits) {
        if (digits.empty()) return {};
        std::queue<std::string> q;
        q.push("");
        for (auto d : digits) {
            std::queue<std::string> next;
            while (!q.empty()) {
                for (auto c : letters[d - '2']) {
                    auto s = q.front();
                    s.push_back(c);
                    next.push(std::move(s));
                }
                q.pop();
            }
            q = std::move(next);
        }
        std::vector<std::string> acc;
        while (!q.empty()) {
            acc.push_back(std::move(q.front()));
            q.pop();
        }
        return acc;
    }
};
