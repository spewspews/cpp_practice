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
            int off1;
            int off2;
        };
    };
};

std::ostream &
operator<<(std::ostream &o, const Instr &i) {
    switch (i.type) {
    case InstrT::FORK:
        return o << "FORK(off1=" << i.off1 << ", off2=" << i.off2 << ")";
    case InstrT::DOT:
        return o << "DOT";
    case InstrT::CHAR:
        return o << "CHAR(c=" << i.c << ")";
    }
}

template <class V>
class UniqueList {
  public:
    using iterator = std::list<V>::iterator;
    void push_back(V i) {
        if (added.contains(i)) return;
        added.insert(i);
        list.push_back(i);
    }
    void clear() { added.clear(), list.clear(); }
    bool empty() { return list.empty(); }
    iterator begin() { return list.begin(); }
    iterator end() { return list.end(); }

  private:
    std::unordered_set<V> added;
    std::list<V> list;
};

class Solution {
  public:
    char *parse(char *c, const char *end, std::vector<Instr> &instrs) {
        auto prev = 0;
        for (; c < end; ++c) {
            switch (*c) {
            default:
                instrs.emplace_back(InstrT::CHAR);
                instrs.back().c = *c;
                prev = 1;
                break;
            case '(': {
                auto prevSize = instrs.size();
                c = parse(c + 1, end, instrs);
                prev = instrs.size() - prevSize;
                if (*c != ')') throw std::runtime_error("Expected ')'");
                break;
            }
            case ')':
                return c;
            case '*': {
                auto i = instrs.emplace(instrs.end() - prev, InstrT::FORK);
                i->off1 = 1;
                i->off2 = prev + 2;
                instrs.emplace_back(InstrT::FORK);
                instrs.back().off1 = -prev;
                instrs.back().off2 = 1;
                prev = prev + 2;
                break;
            }
            case '?': {
                auto i = instrs.emplace(instrs.end() - prev, InstrT::FORK);
                i->off1 = 1;
                i->off2 = prev + 1;
                prev = prev + 1;
                break;
            }
            case '+':
                instrs.emplace_back(InstrT::FORK);
                instrs.back().off1 = -prev;
                instrs.back().off2 = 1;
                prev = prev + 1;
                break;
            case '.':
                instrs.emplace_back(InstrT::DOT);
                prev = 1;
                break;
            }
        }
        return c;
    }

    auto end(const auto &c) { return c.data() + c.size(); }

    bool isMatch(std::string s, std::string p) {
        std::vector<Instr> instrs;
        auto c = parse(p.data(), end(p), instrs);
        if (c != end(p)) throw std::runtime_error("Could not parse");
        UniqueList<Instr *> threads, next;
        threads.push_back(instrs.data());
        for (auto c : s) {
            if (threads.empty()) return false;
            for (auto t : threads) {
                if (t == end(instrs)) continue;
                switch (t->type) {
                case InstrT::CHAR:
                    if (c == t->c) next.push_back(t + 1);
                    break;
                case InstrT::DOT:
                    next.push_back(t + 1);
                    break;
                case InstrT::FORK:
                    threads.push_back(t + t->off1);
                    threads.push_back(t + t->off2);
                    break;
                }
            }
            threads = std::move(next);
            next.clear();
        }
        for (auto t : threads) {
            while (t < end(instrs) && t->type == InstrT::FORK) t = t + t->off2;
            if (t == end(instrs)) return true;
        }
        return false;
    }
};
