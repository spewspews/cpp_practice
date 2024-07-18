#pragma once

#include <sstream>
#include <string>

class Solution {
  public:
    std::string reverseWords(std::string s) {
        std::reverse(s.begin(), s.end());
        std::ostringstream out;
        auto send = s.end();
        for (; send > s.begin(); --send)
            if (*(send - 1) != ' ') break;
        for (auto end = s.begin(); end < send; ++end) {
            for (; end < send; ++end)
                if (*end != ' ') break;
            auto begin = end;
            for (; end < send; ++end)
                if (*end == ' ') break;
            for (auto i = end - 1; i >= begin; --i) out.put(*i);
            out.put(' ');
        }
        auto ret = out.str();
        if (ret.back() == ' ') ret.pop_back();
        return ret;
    }
};
