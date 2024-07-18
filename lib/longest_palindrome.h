#pragma once

#include <list>
#include <string>

class Solution {
  public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        std::list<std::pair<std::string::iterator, std::string::iterator>>
            palindromes;
        for (auto i = s.begin(); i < s.end(); ++i) {
            palindromes.emplace_back(i, i + 1);
            if (i + 1 < s.end() && *i == *(i + 1))
                palindromes.emplace_back(i, i + 2);
        }
        decltype(palindromes.begin()) next;
        std::string_view palindrome;
        while (!palindromes.empty()) {
            for (auto pi = palindromes.begin(); pi != palindromes.end();
                 pi = next) {
                auto &[i, j] = *pi;
                if (palindrome.size() < j - i)
                    palindrome = std::string_view(i, j);
                next = std::next(pi);
                if (i == s.begin() || j == s.end() || *(i - 1) != *j) {
                    palindromes.erase(pi);
                    continue;
                }
                --i;
                ++j;
            }
        }
        return std::string(palindrome);
    }
};
