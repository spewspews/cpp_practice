#pragma once

#include <list>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

enum class InstrT {
    FORK,
    CHAR,
    DOT,
};

class Instr {
  public:
    Instr(InstrT type) : type(type) {}
    InstrT type;
    union {
        char c;
        struct {
            int skip1;
            int skip2;
        };
    };
};

template <class V>
class UniqueList {
  public:
    std::unordered_set<V> added;
    std::list<V> list;
    void add(std::list<V>::iterator at, V i) {
        if (added.contains(i)) return;
        added.insert(i);
        list.insert(at, i);
    }
    void add(V i) { add(list.end(), i); }
    void clear() { added.clear(), list.clear(); }
    bool empty() { return list.empty(); }
};

class Solution {
  public:
    std::vector<Instr> parse(const std::string &p) {
        std::vector<Instr> instrs;
        if (p.empty()) return instrs;
        for (auto i = p.begin(); i < p.end(); ++i) {
            if (i < p.end() - 1 && *(i + 1) == '*') {
                instrs.emplace_back(InstrT::FORK);
                instrs.back().skip1 = 1;
                instrs.back().skip2 = 3;
                if (*i == '.') instrs.emplace_back(InstrT::DOT);
                else {
                    instrs.emplace_back(InstrT::CHAR);
                    instrs.back().c = *i;
                }
                instrs.emplace_back(InstrT::FORK);
                instrs.back().skip1 = -1;
                instrs.back().skip2 = 1;
                ++i;
                continue;
            }
            if (*i == '.') {
                instrs.emplace_back(InstrT::DOT);
                continue;
            }
            instrs.emplace_back(InstrT::CHAR);
            instrs.back().c = *i;
        }
        return instrs;
    }

    bool isMatch(std::string s, std::string p) {
        auto instrs = parse(p);
        UniqueList<Instr *> threads, next;
        threads.add(instrs.data());
        for (auto c : s) {
            if (threads.empty()) return false;
            for (auto ti = threads.list.begin(); ti != threads.list.end();
                 ++ti) {
                auto t = *ti;
                if (t == instrs.data() + instrs.size()) continue;
                switch (t->type) {
                case InstrT::CHAR:
                    if (c == t->c) next.add(t + 1);
                    break;
                case InstrT::DOT:
                    next.add(t + 1);
                    break;
                case InstrT::FORK:
                    threads.add(std::next(ti), t + t->skip1);
                    threads.add(std::next(ti), t + t->skip2);
                    break;
                }
            }
            threads = std::move(next);
            next.clear();
        }
        for (auto t : threads.list) {
            while (t < instrs.data() + instrs.size() && t->type == InstrT::FORK)
                t = t + t->skip2;
            if (t == instrs.data() + instrs.size()) return true;
        }
        return false;
    }
};
