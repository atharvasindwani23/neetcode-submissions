class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;

        // first column
        for (int i = 1; i < rows; i++) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = dp[i - 1][0];
        }

        // first row
        for (int j = 1; j < cols; j++) {
            if (obstacleGrid[0][j] == 1) break;
            dp[0][j] = dp[0][j - 1];
        }

        // rest of the grid
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
