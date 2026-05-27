class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    std::cout << i << std::endl;
                    std::cout << j << std::endl;
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
    //count number of times i have to dfs until we end up visiting every 1, "every island".
    void dfs(int i, int j, vector<vector<char>>& grid) {

    
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.at(0).size() || grid[i][j] == '0') {
            std::cout << "meow?"<<std::endl;
            return;
        }
        grid[i][j] = '0';
        std::cout << i << std::endl;
        std::cout << j << std::endl;
        dfs(i + 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i - 1, j, grid);
        dfs(i, j - 1, grid);
    }





    //classic q which has to deal with number of conencted componenets
    //if this q coes heres how you would explain it, if i were to imagine a graph i would basically, be saying that the 1s are the vertices and there exists a biderectional edge between every two 1s, now if we know two ones arent connected its if they are surrounded by water, so they form a different connected component
    // 1-1-1-1-1-1
    // if (arr[i][j] == 1 and nei(arr[i][j]) == 1 -> extend an edge, then count the number of connected components in the graph)
};
