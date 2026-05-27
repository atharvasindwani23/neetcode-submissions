class Solution {
public:
    vector<bool> values;
    std::set<std::pair<int,int>> visited; 
    bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(0).size(); j++) {
            if (checker(0, word, board, i, j)) {
                return true;
            }
        }
     }
     return false;
    }
    bool checker(int i , string word, vector<vector<char>>& board, int row, int col) {
        if (i == word.size()) {
            return true;
        }
        if (i > word.size() || row < 0 || row >= board.size() || col < 0 || col >= board.at(0).size() || board[row][col] != word[i] || visited.count({row,col})) {
            return false;
        }
        visited.insert({row, col});
        bool res = checker(i + 1, word, board, row + 1, col) || checker(i + 1, word, board, row - 1, col) || checker(i + 1, word, board, row, col + 1) || checker(i + 1, word, board, row, col - 1);
        visited.erase({row, col});
        return res;
    }
};
