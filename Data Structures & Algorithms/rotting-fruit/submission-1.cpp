class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        // Queue to store the coordinates {row, col} of rotten oranges
        queue<pair<int, int>> q;
        int fresh_oranges = 0;

        // 1. Initialize the queue and count fresh oranges
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c}); // Add all initial rotten oranges to the queue
                } else if (grid[r][c] == 1) {
                    fresh_oranges++; // Count the total number of fresh oranges
                }
            }
        }

        // The time elapsed, which is the number of BFS levels
        int minutes = 0;

        // The four possible directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // 2. Perform Multi-Source BFS
        // The loop continues as long as there are oranges to process 
        // AND there are still fresh oranges left to rot
        while (!q.empty() && fresh_oranges > 0) {
            // Get the size of the current level.
            // All oranges currently in the queue rot at the same minute.
            int oranges_at_this_minute = q.size();
            
            // Process all oranges that rot at 'minutes'
            for (int i = 0; i < oranges_at_this_minute; ++i) {
                pair<int, int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                // Check all 4 neighbors
                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j]; // New row
                    int nc = c + dc[j]; // New column

                    // Check bounds and if the neighbor is a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        // This fresh orange now rots
                        grid[nr][nc] = 2; 
                        // Decrement the count of fresh oranges
                        fresh_oranges--; 
                        // Add the newly rotten orange to the queue for the next minute
                        q.push({nr, nc});
                    }
                }
            }
            
            // One full level/minute has passed, but only if we processed at least one new orange.
            // Since fresh_oranges > 0 ensures we're still rotting things, 
            // we can safely increment minutes here.
            minutes++;
        }

        // 3. Final Check
        // If fresh_oranges is 0, all oranges rotted, return the minutes elapsed.
        // Otherwise, some fresh oranges are unreachable, return -1.
        return fresh_oranges == 0 ? minutes : -1;
    }
};