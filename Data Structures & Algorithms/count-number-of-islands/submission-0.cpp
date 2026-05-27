class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int returner = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    returner++;
                    dfs(grid, i, j);
                }
            }
        }
        return returner;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid.at(0).size() || grid[r][c] == '0') {
            return;
        }
        std::cout << r << std::endl;
        std::cout << c << std::endl;
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};
