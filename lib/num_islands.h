#pragma once

#include <queue>
#include <vector>

class Solution {
    using size_t = std::vector<std::vector<char>>::size_type;
    size_t m, n;

  public:
    void markIslandBFS(size_t i, size_t j,
                       std::vector<std::vector<char>> &grid) {
        std::queue<std::pair<size_t, size_t>> q;
        auto push = [&grid, &q](size_t i, size_t j) {
            grid[i][j] = 'X';
            q.emplace(i, j);
        };
        push(i, j);
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i > 0 && grid[i - 1][j] == '1') push(i - 1, j);
            if (j > 0 && grid[i][j - 1] == '1') push(i, j - 1);
            if (i + 1 < m && grid[i + 1][j] == '1') push(i + 1, j);
            if (j + 1 < n && grid[i][j + 1] == '1') push(i, j + 1);
        }
    }

    void markIslandDFS(size_t i, size_t j,
                       std::vector<std::vector<char>> &grid) {
        grid[i][j] = 'X';
        if (i > 0 && grid[i - 1][j] == '1') markIslandDFS(i - 1, j, grid);
        if (j > 0 && grid[i][j - 1] == '1') markIslandDFS(i, j - 1, grid);
        if (i + 1 < m && grid[i + 1][j] == '1') markIslandDFS(i + 1, j, grid);
        if (j + 1 < n && grid[i][j + 1] == '1') markIslandDFS(i, j + 1, grid);
    }

    int numIslands(std::vector<std::vector<char>> &grid) {
        m = grid.size();
        n = grid.front().size();
        int num = 0;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (grid[i][j] != '1') continue;
                ++num;
                markIslandDFS(i, j, grid);
            }
        }
        return num;
    }
};
