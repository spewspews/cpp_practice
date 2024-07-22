#pragma once

#include <string>
#include <string_view>
#include <unordered_set>

class SolutionBacktrack {
    using iter = std::string::iterator;

  public:
    bool isMatch(iter s, iter send, iter p, iter pend) {
        for (;;) {
            if (p == pend) return s == send;
            switch (*p) {
            default:
                if (s == send || *p != *s) return false;
                break;
            case '?':
                if (s == send) return false;
                break;
            case '*': {
                auto prev = p;
                for (auto it = p + 1; it < pend; ++it) {
                    if (*it != '*') break;
                    prev = it;
                }
                p = prev;
                if (s != send) {
                    if (isMatch(s + 1, send, p, pend)) return true;
                }
                if (isMatch(s, send, p + 1, pend)) return true;
                if (s == send) return false;
            } break;
            }
            ++s;
            ++p;
        }
    }

    bool isMatch(std::string s, std::string p) {
        return isMatch(s.begin(), s.end(), p.begin(), p.end());
    }
};

class Solution {
  public:
    void clean(std::string &p) {
        char prev = '\0';
        std::erase_if(p, [&prev](char c) {
            bool e = false;
            if (c == '*' && prev == '*') e = true;
            prev = c;
            return e;
        });
    }

    bool isMatch(std::string s, std::string p) {
        clean(p);
        std::unordered_set<char *> threads, next;
        auto t = p.data();
        threads.insert(t);
        for (auto c : s) {
            if (threads.empty()) return false;
            for (auto t : threads) {
                for (;;) {
                    if (t == p.data() + p.size()) break;
                    switch (*t) {
                    default:
                        if (c == *t) next.insert(t + 1);
                        break;
                    case '?':
                        next.insert(t + 1);
                        break;
                    case '*':
                        next.insert(t);
                        next.insert(t + 1);
                        ++t;
                        continue;
                    }
                    break;
                }
            }
            std::swap(threads, next);
            next.clear();
        }
        for (auto t : threads) {
            while (t < p.data() + p.size() && *t == '*') ++t;
            if (t == p.data() + p.size()) return true;
        }
        return false;
    }
};
