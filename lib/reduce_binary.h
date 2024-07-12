#pragma once

#include <cstring>
#include <iostream>
#include <string>

class Solution {
  public:
    int numSteps(std::string s) {
        auto end = s.data() + s.size();
        auto i = end - 1;
        while (*i == '0') --i;
        int steps = end - 1 - i;
        if (i == s.data()) return steps;
        end = i + 1;
        *end = '\0';
        i = s.data();
        for (;;) {
            char *next = (char *)std::memchr(i, '0', end - i);
            if (next == nullptr) {
                steps += end - i + 1;
                break;
            }
            steps += next - i + 2;
            i = next;
            next = (char *)memchr(i, '1', end - i);
            steps += 2 * (next - i - 1);
            i = next;
        }
        return steps;
    }
};
