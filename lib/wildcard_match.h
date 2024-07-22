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
    using iter = std::string::iterator;
    using threads_t = std::unordered_set<std::string::size_type>;

  public:
    bool isMatch(std::string s, std::string p) {
        if (s.empty() && p.empty()) return true;
        if (p.empty()) return false;
        threads_t threads, next;
        auto t = p.begin();
        if (*t == '*') {
            for (; t < p.end(); ++t) {
                if (*t != '*') break;
            }
            --t;
        }
        auto add_thread = [begin = p.begin()](threads_t &threads, iter t) {
            threads.insert(t - begin);
        };
        add_thread(next, t);
        if (*t == '*') add_thread(next, t + 1);
        for (auto c : s) {
            std::swap(threads, next);
            next.clear();
            if (threads.empty()) return false;
            for (auto offset : threads) {
                auto t = p.begin() + offset;
                for (;;) {
                    if (t == p.end()) break;
                    switch (*t) {
                    default:
                        if (*t == c) add_thread(next, t + 1);
                        break;
                    case '?':
                        add_thread(next, t + 1);
                        break;
                    case '*':
                        for (; t < p.end(); ++t) {
                            if (*t != '*') break;
                        }
                        add_thread(next, t - 1);
                        add_thread(next, t);
                        continue;
                    }
                    break;
                }
            }
        }
        for (auto offset : next) {
            auto t = p.begin() + offset;
            while (t < p.end() && *t == '*') ++t;
            if (t == p.end()) return true;
        }
        return false;
    }
};
