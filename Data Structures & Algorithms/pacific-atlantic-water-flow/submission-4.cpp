class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        map<pair<int,int>, bool> canReachPacific;
        queue<pair<int,int>> pacificSources;
        map<pair<int,int>, bool> canReachAtlantic;
        queue<pair<int,int>> atlanticSources;

        int n = heights.size();
        int m = heights[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                 canReachPacific[{i, j}] = true;
                 pacificSources.push({i, j});   
                }
                if (i == n - 1 || j == m - 1) {
                    canReachAtlantic[{i, j}] = true;
                    atlanticSources.push({i, j});
                }
            }
        }

        bfs(pacificSources, canReachPacific, heights);
        bfs(atlanticSources, canReachAtlantic, heights);

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (canReachAtlantic[{i, j}] && canReachPacific[{i, j}]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void bfs(queue<pair<int,int>> sources, map<pair<int,int>, bool>& reach, vector<vector<int>>& heights) {
        while (!sources.empty()) {
            int curr_row = sources.front().first;
            int curr_col = sources.front().second;
            sources.pop();

            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

            for (int i = 0; i < 4; i++) {
                int row = curr_row + directions[i][0];
                int col = curr_col + directions[i][1];

                if (row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size() || heights[curr_row][curr_col] > heights[row][col]) {
                    continue;
                }
                if (!reach[{row, col}]) {
                reach[{row, col}] = true;
                sources.push({row, col});
                }
            }
        }
    }



    // pacific ocean -> [top, left]
    // atlantic ocean -> [bottom, right]
};
