class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        queue<pair<int,int>> sources;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    sources.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        int minutes = 0;            

        while (!sources.empty() && freshOranges > 0) {

            int rottenSize = sources.size();

            for (int i = 0; i < rottenSize; i++) {
                int curr_row = sources.front().first;
                int curr_col = sources.front().second;
                sources.pop();
                vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

                for (int i = 0; i < 4; i++) {
                    int row = curr_row + directions[i][0];
                    int col = curr_col + directions[i][1];

                    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1) {
                        continue;
                    }
                    grid[row][col] = 2;
                    freshOranges--;
                    sources.push({row, col});
                }
            }
            minutes++;
        }
        if (freshOranges == 0) {
            return minutes;
        }
        return -1;
    }
};
