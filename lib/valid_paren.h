#pragma once

#include <deque>
#include <string>

class Solution {
  public:
    bool isValid(std::string s) {
        std::deque<char> stack;
        std::unordered_map<char, char> match = {
            {')', '('}, {'}', '{'}, {']', '['}};
        for (auto c : s) {
            switch (c) {
            case '(':
            case '{':
            case '[':
                stack.push_front(c);
                break;
            case ')':
            case '}':
            case ']':
                if (stack.front() == match[c]) stack.pop_front();
                else return false;
                break;
            }
        }
        return stack.empty();
    }
};
