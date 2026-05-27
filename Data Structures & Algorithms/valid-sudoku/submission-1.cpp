class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row, //set, //squares
        //map -> [idx, set]
        map<int, set<char>> rows;
        map<int, set<char>> cols;
        map<pair<int,int>, set<char>> squares;
        for (int i  = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char grid = board[i][j];
                if (grid == '.') {
                    continue;
                }
                pair<int,int> squareKey = {i / 3, j / 3};
                if (rows[i].count(grid) || cols[j].count(grid) || squares[squareKey].count(grid)) {
                    return false;
                }
                rows[i].insert(grid);
                cols[j].insert(grid);
                squares[squareKey].insert(grid);
            }
        }
        return true;
    }
};
