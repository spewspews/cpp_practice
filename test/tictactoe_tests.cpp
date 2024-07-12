#include <gtest/gtest.h>

#include <tictactoe.h>

class TicTacToeTests : public testing::Test {
protected:
  TicTacToe *ttt;
  virtual void SetUp() { ttt = new TicTacToe(3); }
  virtual void TearDown() { delete ttt; }
  void setBoard(int n) {
    delete ttt;
    ttt = new TicTacToe(n);
  }
};

TEST_F(TicTacToeTests, FirstMoveZero) { ASSERT_EQ(ttt->move(0, 0, 1), 0); }

TEST_F(TicTacToeTests, TrivialWin) {
  ASSERT_EQ(ttt->move(0, 0, 1), 0);
  ASSERT_EQ(ttt->move(1, 0, 1), 0);
  ASSERT_EQ(ttt->move(2, 0, 1), 1);
}

TEST_F(TicTacToeTests, SimpleGame) {
  ASSERT_EQ(ttt->move(0, 0, 1), 0);
  ASSERT_EQ(ttt->move(0, 2, 2), 0);
  ASSERT_EQ(ttt->move(2, 2, 1), 0);
  ASSERT_EQ(ttt->move(1, 1, 2), 0);
  ASSERT_EQ(ttt->move(2, 0, 1), 0);
  ASSERT_EQ(ttt->move(1, 0, 2), 0);
  ASSERT_EQ(ttt->move(2, 1, 1), 1);
}
