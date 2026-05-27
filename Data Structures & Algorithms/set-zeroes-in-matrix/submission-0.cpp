class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> copier = matrix;
        vector<int> row_zero;
        vector<int> col_zero; 
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            vector<int> col = matrix[i];
            for (int j = 0; j < col.size(); j++) {
                if (matrix[i][j] == 0) {
                    //transform the i^th row to all 0's and transform the j^th col to all 0's
                    row_zero.push_back(i);
                    col_zero.push_back(j);
                }
            }
        }
        for (int idx : row_zero) {
            for (int i = 0; i < cols; i++) {
                matrix[idx][i] = 0;
            }
        }
        for (int idx : col_zero) {
            for (int i = 0; i < rows; i++) {
                matrix[i][idx] = 0;
            }
        }

    }
};
