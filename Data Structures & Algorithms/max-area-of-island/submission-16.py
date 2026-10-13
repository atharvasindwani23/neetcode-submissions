class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        res = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    res = max(res, self.dfs(grid, i, j))
            
        return res
        
    def dfs(self, grid:List[List[int]], i: int, j:int) -> int:
        res = 0

        n = len(grid)

        m = len(grid[0])

        if i >= n or j >=m or i < 0 or j < 0 or grid[i][j] == 0:
            return 0
        
        grid[i][j] = 0
        return 1 + self.dfs(grid, i + 1, j) + self.dfs(grid, i, j + 1) + self.dfs(grid, i - 1, j) + self.dfs(grid, i, j - 1)
        