#pragma once

#include <set>
#include <stdexcept>
#include <string>
#include <vector>

class Instr {
  public:
    Instr(char type, char c) : type(type), c(c) {}
    char type;
    char c;
};

class Solution {
    using iter = std::vector<Instr>::iterator;
    using size_type = std::vector<Instr>::size_type;

  public:
    std::vector<Instr> parse(const std::string &p) {
        std::vector<Instr> instrs;
        for (auto i = p.begin(); i < p.end(); ++i) {
            if (i < p.end() - 1 && *(i + 1) == '*') {
                instrs.emplace_back('*', *i);
                ++i;
                continue;
            }
            instrs.emplace_back(*i, *i);
        }
        return instrs;
    }

    bool isMatch(std::string s, std::string p) {
        auto instrs = parse(p);
        std::set<iter> threads, next;
        next.insert(instrs.begin());
        for (auto c : s) {
            std::swap(threads, next);
            next.clear();
            if (threads.empty()) return false;
            for (auto t : threads) {
                for (;;) {
                    if (t == instrs.end()) break;
                    switch (t->type) {
                    default:
                        if (c == t->c) next.insert(t + 1);
                        break;
                    case '.':
                        next.insert(t + 1);
                        break;
                    case '*':
                        if (t->c == '.' || c == t->c) {
                            next.insert(t);
                            next.insert(t + 1);
                        }
                        ++t;
                        continue;
                    }
                    break;
                }
            }
        }
        for (auto t : next) {
            while (t != instrs.end() && t->type == '*') ++t;
            if (t == instrs.end()) return true;
        }
        return false;
    }
};
