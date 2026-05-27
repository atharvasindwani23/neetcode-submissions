class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int INF = (int)(pow(2,31)) - 1;
        queue<pair<int,int>> sources;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    sources.push({i, j});
                }
            }
        }
        while (!sources.empty()) {
            int row = sources.front().first;
            int col = sources.front().second;
            sources.pop();
            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};   

            for (int i = 0; i < 4; i++) {
                int row_offset = directions[i][0];
                int col_offset = directions[i][1];

                int r = row + row_offset;
                int c = col + col_offset;
                cout << r << endl;
                cout << c << endl;
                if (r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] != INT_MAX) {
                    cout << "everytime??";
                    continue;
                }
                cout << "pwease print" << endl;
                grid[r][c] = grid[row][col] + 1;
                sources.push({r,c});
            }
        }
    }
};
