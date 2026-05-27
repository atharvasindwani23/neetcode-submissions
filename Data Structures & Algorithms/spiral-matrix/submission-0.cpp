class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.at(0).size() - 1;
        int bottom = 0;
        int top = matrix.size() - 1;
        vector<int> returner;
        int direction = 0;
        while (left <= right && bottom <= top) {
            if (direction == 0) {
                for (int i = left; i <= right; i++) {
                    returner.push_back(matrix[bottom][i]);
                }
                bottom++;
                direction = 1;
            } else if (direction == 1) {
                for (int i = bottom; i <= top; i++) {
                    returner.push_back(matrix[i][right]);
                }
                right--;
                direction = 2;
            } else if (direction == 2) {
                for (int i = right; i >= left; i--) {
                    returner.push_back(matrix[top][i]);
                }
                top--;
                direction = 3;
            } else {
                for (int i = top; i >= bottom; i--) {
                    returner.push_back(matrix[i][left]);
                }
                left++;
                direction = 0;
            }
        }
        return returner;
    }
};
