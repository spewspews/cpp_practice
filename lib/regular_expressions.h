#pragma once

#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

class Instr {
  public:
    Instr(char type, char c) : type(type), c(c) {}
    char type;
    char c;
};

class Solution {
  public:
    std::vector<Instr> parse(const std::string &p) {
        std::vector<Instr> instrs;
        if (p.empty()) return instrs;
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
        std::unordered_set<Instr *> threads, next;
        threads.insert(instrs.data());
        for (auto c : s) {
            if (threads.empty()) return false;
            for (auto t : threads) {
                for (;;) {
                    if (t == instrs.data() + instrs.size()) break;
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
            std::swap(threads, next);
            next.clear();
        }
        for (auto t : threads) {
            while (t < instrs.data() + instrs.size() && t->type == '*') ++t;
            if (t == instrs.data() + instrs.size()) return true;
        }
        return false;
    }
};
