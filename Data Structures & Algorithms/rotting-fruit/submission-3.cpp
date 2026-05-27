class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> sources;
        int freshOranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    sources.push({i, j});
                }
                if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int levels = 0;

        while (!sources.empty() && freshOranges > 0) {

            int len = sources.size();

            for (int i = 0; i < len; i++) {

                pair<int,int> curr = sources.front();
                sources.pop();
                vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

                for (int j = 0; j < 4; j++) {
                    int true_x = curr.first + directions[j][0];
                    int true_y = curr.second + directions[j][1];

                    if (true_x < 0 || true_x >= grid.size() || true_y < 0 || true_y >= grid[0].size()) {
                        continue;
                    }
                    if (grid[true_x][true_y] == 1) {
                        grid[true_x][true_y] = 2;
                        sources.push({true_x, true_y});
                        freshOranges--;
                    }
                }
            }
            levels++;
        }
        if (freshOranges == 0) return levels;
        return -1;
    }

    //number of levels within the tree
};
