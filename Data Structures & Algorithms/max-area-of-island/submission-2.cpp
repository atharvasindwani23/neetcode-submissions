class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i  = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int c = 0;
                    dfs(grid, i, j, c);
                    res = max(res, c);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>&grid, int i, int j, int& c) {
        if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        c++;
        dfs(grid, i + 1, j, c);
        dfs(grid, i - 1, j, c);
        dfs(grid, i , j - 1, c);
        dfs(grid, i, j + 1, c);
    }

    //stop complicating it, its essentially the largest sequence of conencted ones 
};
