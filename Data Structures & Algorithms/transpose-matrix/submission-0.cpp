class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        //your goal is to TRANSPOSE THE MATRIX
        //ith row becomes ith column
        vector<vector<int>> vec(matrix[0].size(), vector<int>(matrix.size()));
        for (int i  = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(0).size(); j++) {
                vec[j][i] = matrix[i][j];
            }
        }
        return vec;

     //ith row becomes ith column and so on how can we do this, we have access to all the rows right?
        
    }
};