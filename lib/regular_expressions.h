#pragma once

#include <list>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

enum class InstrT {
    SPLIT,
    MATCH,
};

class NewInstr {
  public:
    NewInstr(InstrT type) : type(type) {}
    InstrT type;
    union {
        char c;
        struct {
            std::size_t skip1;
            std::size_t skip2;
        };
    };
};

class Instr {
  public:
    Instr(char type, char c) : type(type), c(c) {}
    char type;
    char c;
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
    std::vector<NewInstr> newParse(const std::string &p) {
        std::vector<NewInstr> instrs;
        if (p.empty()) return instrs;
        for (auto i = p.begin(); i < p.end(); ++i) {
            if (i < p.end() - 1 && *(i + 1) == '*') {
                instrs.emplace_back(InstrT::SPLIT);
                instrs.back().skip1 = 0;
                instrs.back().skip2 = 1;
                instrs.emplace_back(InstrT::MATCH);
                instrs.back().c = *i;
                ++i;
                continue;
            }
            instrs.emplace_back(InstrT::MATCH);
            instrs.back().c = *i;
        }
        return instrs;
    }
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
        UniqueList<Instr *> threads, next;
        threads.add(instrs.data());
        for (auto c : s) {
            if (threads.empty()) return false;
            for (auto ti = threads.list.begin(); ti != threads.list.end();
                 ++ti) {
                auto t = *ti;
                if (t == instrs.data() + instrs.size()) continue;
                switch (t->type) {
                default:
                    if (c == t->c) next.add(t + 1);
                    break;
                case '.':
                    next.add(t + 1);
                    break;
                case '*':
                    if (t->c == '.' || c == t->c) {
                        next.add(t);
                        next.add(t + 1);
                    }
                    threads.add(std::next(ti), t + 1);
                    break;
                }
            }
            threads = std::move(next);
            next.clear();
        }
        for (auto t : threads.list) {
            if (t < instrs.data() + instrs.size())
                std::cout << " t=" << t->type << ',' << t->c << std::endl;
            while (t < instrs.data() + instrs.size() && t->type == '*') ++t;
            if (t == instrs.data() + instrs.size()) return true;
        }
        return false;
    }
};
