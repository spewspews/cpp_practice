#pragma once

#include <vector>

class TicTacToe {
  class PlayerScore {
    std::vector<int> rows;
    std::vector<int> cols;
    int diag1, diag2, size;

  public:
    PlayerScore(int n) : rows(n), cols(n), diag1(0), diag2(0), size(n) {}

    bool move(int row, int col) {
      if (++rows[row] == size) return true;
      if (++cols[col] == size) return true;
      if (row == col && ++diag1 == size) return true;
      if (row == (size - 1 - col) && ++diag2 == size) return true;
      return false;
    }
  };

  std::vector<PlayerScore> scores;

public:
  TicTacToe(int n) {
    scores.emplace_back(n);
    scores.emplace_back(n);
  }

  int move(int row, int col, int player) {
    if (scores[player - 1].move(row, col)) return player;
    return 0;
  }
};
