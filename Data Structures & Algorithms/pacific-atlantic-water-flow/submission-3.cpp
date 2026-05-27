class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> returner;
        int m = heights.size(), n = heights[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool paci = false;
                bool atlan = false;
                std::set<std::pair<int, int>> visited;  // LOCAL
                if (helper(heights, i, j, INT_MAX, paci, atlan, visited)) {
                    returner.push_back({i,j});
                }
            }
        }
        return returner;
    }

    bool helper(vector<vector<int>>& heights, int row, int col, int val, bool &paci, bool &atlan, std::set<std::pair<int, int>>& visited) {
        int m = heights.size(), n = heights[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n || val < heights[row][col] || visited.count({row,col})) {
            return false;
        }

        visited.insert({row, col});
        if (row == 0 || col == 0) paci = true;
        if (row == m - 1 || col == n - 1) atlan = true;
        if (paci && atlan) return true;

        bool res = helper(heights, row + 1, col, heights[row][col], paci, atlan, visited) ||
                   helper(heights, row - 1, col, heights[row][col], paci, atlan, visited) ||
                   helper(heights, row, col + 1, heights[row][col], paci, atlan, visited) ||
                   helper(heights, row, col - 1, heights[row][col], paci, atlan, visited);

        visited.erase({row, col}); // backtrack
        return res;
    }
};
