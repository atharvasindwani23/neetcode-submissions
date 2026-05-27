class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size()));
        int rows = grid.size();
        int cols = grid[0].size();
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < cols; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][cols - 1];
    }

    //top left to bottom right
    //dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
};