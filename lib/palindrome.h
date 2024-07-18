#pragma once

#include <locale>
#include <string>

class Solution {
  public:
    inline bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    bool isPalindrome(std::string s) {
        auto f = s.begin();
        auto b = s.end();
        while (f < b - 1) {
            if (!isAlphaNum(*f)) {
                ++f;
                continue;
            }
            if (!isAlphaNum(*(b - 1))) {
                --b;
                continue;
            }
            if (std::tolower(*f) != std::tolower(*(b - 1))) return false;
            ++f;
            --b;
        }
        return true;
    }
};
