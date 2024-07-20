#pragma once

#include <set>
#include <string>
#include <vector>

class Solution {
  public:
    bool findWord(std::vector<std::vector<char>> &board,
                  decltype(board.size()) i, decltype(board[i].size()) j,
                  std::string_view s) {
        if (board[i][j] != s.front()) return false;
        if (s.size() == 1) return true;
        auto tmp = board[i][j];
        board[i][j] = '\0';
        auto found = false;
        if (!found && i > 0 && findWord(board, i - 1, j, s.substr(1)))
            found = true;
        if (!found && i < board.size() - 1 &&
            findWord(board, i + 1, j, s.substr(1)))
            found = true;
        if (!found && j > 0 && findWord(board, i, j - 1, s.substr(1)))
            found = true;
        if (!found && j < board[i].size() - 1 &&
            findWord(board, i, j + 1, s.substr(1)))
            found = true;
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
