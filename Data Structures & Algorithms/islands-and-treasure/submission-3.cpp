class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
      int MAGIC_NUMBER = pow(2, 31) - 1;
      queue<pair<int,int>> sources;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                sources.push({i, j});
            }
        }
      }
      set<pair<int,int>> visited;
      while (!sources.empty()) {
        pair<int, int> curr = sources.front();
        visited.insert(curr);
        sources.pop();
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            int x_offset = directions[i][0];
            int y_offset = directions[i][1];
            int true_x = x_offset + curr.first;
            int true_y = y_offset + curr.second;

            if (true_x < 0 || true_x >= grid.size() || true_y < 0 || true_y >= grid[0].size()){
                continue;
            }

            if (grid[true_x][true_y] == -1) {
                continue;
            }
            if (grid[true_x][true_y] == MAGIC_NUMBER && !visited.count({true_x, true_y})) {
                sources.push({true_x, true_y});
                grid[true_x][true_y] = grid[curr.first][curr.second] + 1;
                visited.insert({true_x, true_y});
            }
        }
      }
    }
    //multi-source bfs you start by collecting all treasure chests and walk beyond, whenever you encounter an INF, add it into your queue, and assign it the correct value;
};
