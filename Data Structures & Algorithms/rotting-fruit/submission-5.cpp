class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //very simple example of a level order traversal where we have to find the number of levels

        queue<pair<int,int>> sources;
        int numOranges = 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    sources.push({i, j});
                }
                if (grid[i][j] == 1) {
                    numOranges++;
                }
            }
        }
        while (numOranges > 0 && !sources.empty()) {
            int len = sources.size();
            count++;
            for (int i = 0; i < len; i++) {
                auto curr = sources.front();
                sources.pop();

                vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

                for (int i = 0; i < directions.size(); i++) {
                    int x = directions[i][0] + curr.first;
                    int y = directions[i][1] + curr.second;
                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) {
                        continue;
                    }
                    grid[x][y] = 2;
                    sources.push({x,y});
                    numOranges--;
                }
            }
        }    
        if (numOranges == 0) {
            return count;
        }
        return -1;  
    }
};
