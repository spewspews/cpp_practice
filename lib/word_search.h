#pragma once

#include <set>
#include <string>
#include <vector>

class SolutionSlow {
  public:
    bool findWord(std::vector<std::vector<char>> &board,
                  decltype(board.size()) i, decltype(board[i].size()) j,
                  std::string_view s) {
        if (board[i][j] != s.front()) return false;
        if (s.size() == 1) return true;
        auto tmp = board[i][j];
        board[i][j] = '\0';
        auto found = [this, &i, &j, &board, &s]() {
            if (i > 0 && findWord(board, i - 1, j, s.substr(1))) return true;
            if (j > 0 && findWord(board, i, j - 1, s.substr(1))) return true;
            if (i < board.size() - 1 && findWord(board, i + 1, j, s.substr(1)))
                return true;
            if (j < board.size() - 1 && findWord(board, i, j + 1, s.substr(1)))
                return true;
            return false;
        }();
        board[i][j] = tmp;
        return found;
    }

    bool findWord(std::vector<std::vector<char>> &board,
                  const std::string &word) {
        if (word.empty()) return false;
        for (decltype(board.size()) i = 0; i < board.size(); ++i) {
            for (decltype(board[i].size()) j = 0; j < board[i].size(); ++j) {
                if (findWord(board, i, j, std::string_view(word))) {
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                       std::vector<std::string> &words) {
        std::vector<std::string> acc;
        for (auto w : words)
            if (findWord(board, w)) acc.push_back(w);
        return acc;
    }
};

class Trie {
  public:
    Trie() : parent(nullptr), val('\0'), term(false), found(false) {}

    ~Trie() {
        for (auto [_, n] : children) delete n;
    }

    void insert(std::string s) {
        auto n = this;
        for (auto c : s) {
            auto &chld = n->children[c];
            if (chld == nullptr) chld = new Trie();
            chld->val = c;
            chld->parent = n;
            n = chld;
        }
        n->term = true;
    }

    void prune(char c) {
        auto f = children.find(c);
        if (f == children.end()) return;
        delete f->second;
        children.erase(f);
    }

    std::string getWord() const {
        std::string s({val});
        auto n = parent;
        while (n != nullptr) {
            s.push_back(n->val);
            n = n->parent;
        }
        s.pop_back();
        std::reverse(s.begin(), s.end());
        return s;
    }

    std::map<char, Trie *> children;
    Trie *parent;
    char val;
    bool term;
    bool found;
};

class Solution {
    using size_type_i = std::vector<std::vector<char>>::size_type;
    using size_type_j = std::vector<char>::size_type;

  public:
    void findWords(std::vector<std::vector<char>> &board, size_type_i i,
                   size_type_j j, Trie *trie, std::vector<std::string> &out) {
        for (auto [c, n] : trie->children) {
            if (c != board[i][j]) continue;
            if (n->term && !n->found) {
                out.push_back(n->getWord());
                n->found = true;
            }
            auto saved = board[i][j];
            board[i][j] = '\0';
            if (i > 0) findWords(board, i - 1, j, n, out);
            if (j > 0) findWords(board, i, j - 1, n, out);
            if (i < board.size() - 1) findWords(board, i + 1, j, n, out);
            if (j < board[i].size() - 1) findWords(board, i, j + 1, n, out);
            board[i][j] = saved;
            if (n->found && n->children.empty()) n->parent->prune(c);
        }
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                       std::vector<std::string> &words) {
        Trie trie;
        for (auto w : words) trie.insert(w);
        std::vector<std::string> found;
        for (size_type_i i = 0; i < board.size(); ++i)
            for (size_type_j j = 0; j < board[i].size(); ++j)
                findWords(board, i, j, &trie, found);
        return found;
    };
};
