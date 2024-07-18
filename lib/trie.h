#pragma once

#include <string>

#include <ankerl/unordered_dense.h>

template <class K, class V>
using map = ankerl::unordered_dense::map<K, V>;

class Trie {
    class Node {
      public:
        Node() : child(), term(false) {}
        ~Node() {
            for (auto n : child) delete n.second;
        }
        map<char, Node *> child;
        bool term;
    };
    Node root;

  public:
    Trie() {}

    Node *find(std::string word, bool create) {
        auto n = &root;
        for (auto w : word) {
            auto &c = n->child[w];
            if (c == nullptr) {
                if (create) c = new Node();
                else return nullptr;
            }
            n = c;
        }
        return n;
    }

    void insert(std::string word) {
        auto n = find(word, true);
        n->term = true;
    }

    bool search(std::string word) {
        auto n = find(word, false);
        return n != nullptr && n->term;
    }

    bool startsWith(std::string prefix) {
        return find(prefix, false) != nullptr;
    }
};
