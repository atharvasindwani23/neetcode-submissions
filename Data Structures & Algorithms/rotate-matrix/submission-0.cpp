class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> copier = matrix;
        int n = matrix.size();
        for (int i = n - 1; i >=0; i--) {
            vector<int> row = copier[i];
            for (int j = 0; j < n; j++) {
                matrix[j][n - i - 1] = copier[i][j];
            }
        }
    }

    // every row becomes a column, vector at posn 0, beocomes 
};
