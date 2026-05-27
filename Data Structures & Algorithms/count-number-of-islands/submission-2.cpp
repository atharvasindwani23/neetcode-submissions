class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //ill run a double loop going through every i,j to locate 1's  and the number of 1's i spot will be my answer
        //
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i , j);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }




    // G(V, E) => V = All the ones which are present
                // E = These hypothetical lines which tie two ones together
                //Ill convert the grid into a graph of (V,E) and then I'll apply some graph traversal problem
};
