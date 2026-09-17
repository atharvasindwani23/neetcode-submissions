#ifndef NEETCODE_COMMON_GRID_H
#define NEETCODE_COMMON_GRID_H

// Helpers for the 2D-grid problems in this repo (number of islands, pacific
// atlantic water flow, rotting oranges, surrounded regions, ...).
//
// The repeated pattern in those submissions is: 4-directional neighbours, a
// bounds check, and a flood-fill (DFS or BFS). Those are centralized here.

#include <array>
#include <cstddef>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

namespace neetcode {

// The four orthogonal moves: up, down, left, right.
inline constexpr std::array<std::pair<int, int>, 4> kDirs4 = {
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

// The eight moves including diagonals.
inline constexpr std::array<std::pair<int, int>, 8> kDirs8 = {
    {{-1, -1}, {-1, 0}, {-1, 1},
     {0, -1},           {0, 1},
     {1, -1},  {1, 0},  {1, 1}}};

template <typename T>
inline bool inBounds(const std::vector<std::vector<T>> &grid, int r, int c) {
    return r >= 0 && c >= 0 && r < static_cast<int>(grid.size()) &&
           c < static_cast<int>(grid[r].size());
}

// Recursive 4-directional flood fill. `shouldVisit(r, c)` decides whether a
// still-unvisited, in-bounds cell belongs to the region; `visit(r, c)` is run
// once per accepted cell (mark visited there).
template <typename T, typename Pred, typename Visit>
void floodFillDfs(std::vector<std::vector<T>> &grid, int r, int c,
                  Pred shouldVisit, Visit visit) {
    if (!inBounds(grid, r, c) || !shouldVisit(r, c)) return;
    visit(r, c);
    for (const auto &[dr, dc] : kDirs4) {
        floodFillDfs(grid, r + dr, c + dc, shouldVisit, visit);
    }
}

// Iterative 4-directional BFS from a single source. Same callback contract as
// floodFillDfs; useful when recursion depth could overflow the stack.
template <typename T, typename Pred, typename Visit>
void floodFillBfs(std::vector<std::vector<T>> &grid, int r, int c,
                  Pred shouldVisit, Visit visit) {
    if (!inBounds(grid, r, c) || !shouldVisit(r, c)) return;
    std::queue<std::pair<int, int>> q;
    visit(r, c);
    q.push({r, c});
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        for (const auto &[dr, dc] : kDirs4) {
            int nr = cr + dr, nc = cc + dc;
            if (inBounds(grid, nr, nc) && shouldVisit(nr, nc)) {
                visit(nr, nc);
                q.push({nr, nc});
            }
        }
    }
}

}  // namespace neetcode

#endif  // NEETCODE_COMMON_GRID_H
