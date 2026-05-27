class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> startingPoints;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    startingPoints.push({i, j});
                }
            }
        }
        bfs(grid, startingPoints);
    }

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>> startingPoints) {
        int INF = 2147483647;
        while (!startingPoints.empty()) {
            int curr_row = startingPoints.front().first;
            int curr_col = startingPoints.front().second;
            startingPoints.pop();

            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (int i = 0; i < 4; i++) {

                int row = curr_row + directions[i][0];
                int col = curr_col + directions[i][1];

                if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != INF) {
                    continue;
                }

                grid[row][col] = grid[curr_row][curr_col] + 1;
                startingPoints.push({row, col});
            }
        }
    }
};
