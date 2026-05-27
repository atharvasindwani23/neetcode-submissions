class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i  = 0; i < grid.size(); i++) {
            for (int j  = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    res = max(res, bfs(grid, i , j));
                }
            }
        }
        return res;
    }

    int bfs(vector<vector<int>>& grid, int i ,int j) {
        pair<int,int> coords = {i, j};
        if (grid.size() == 1 && grid[0].size() == 1) {
            return 1;
        }
        grid[i][j] = 0;
        queue<pair<int,int>> q;
        q.push(coords);
        int count = 1;
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            if (row < grid.size() - 1 && grid[row + 1][col] == 1) {
                q.push({row + 1, col});
                grid[row + 1][col] = 0;
                count++;
            }
            if (row > 0 && grid[row - 1][col] == 1) {
                q.push({row - 1, col});
                grid[row - 1][col] = 0;
                count++;
            }
            if (col > 0 && grid[row][col - 1] == 1) {
                q.push({row, col - 1});
                grid[row][col - 1] = 0;
                count++;
            }
            if (col < grid[0].size() - 1 && grid[row][col + 1] == 1) {
                q.push({row, col + 1});
                grid[row][col + 1] = 0;
                count++;
            }
         }
         return count;
    }

};
