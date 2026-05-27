class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lower = 0;
        int upper = rows * cols - 1;
        
        while (lower <= upper) {
            int mid = lower + (upper - lower) / 2;
            int row = mid / cols;
            int col = mid % cols;
            
            int val = matrix[row][col];
            
            if (val == target) {
                return true;
            } else if (val < target) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return false;
    }
};
