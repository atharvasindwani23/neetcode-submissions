class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
      map<pair<int,int>, bool> visited;
      map<pair<int,int>, int> distance;
      queue<pair<int,int>> q;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
              if (grid[i][j] == 0) {
                q.push({i,j});
                visited[{i,j}] = true;
                distance[{i,j}] = 0;
              }
            }
        }
        while (q.size() > 0) {
            auto x = q.front();
            q.pop();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (auto dir : directions) {
                int row = x.first + dir.first;
                int col = x.second + dir.second;
                if (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] != -1) {
                    if (!visited[{row,col}]) {
                        visited[{row,col}] = true;
                        distance[{row, col}] = distance[x] + 1; 
                        grid[row][col] = distance[x] + 1;
                        q.push({row,col});
                    }
                }
            }
        }
      }  
     };
