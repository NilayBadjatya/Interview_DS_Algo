class Solution {
public:
    bool validSudoku(vector<vector<char>>& board, int row, int col, int val) {
        for(int i = 0; i < 9; i++){
            if(board[i][col] == (val + '0')) return false;
            if(board[row][i] == (val + '0')) return false;
            if (board[3 * (row/3) + i/3][3 * (col/3) + i%3] == (val + '0')) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (int val = 1; val <= 9; val++) {
                        if(validSudoku(board, i, j, val)){
                            board[i][j] = (val + '0');
                            bool isValid = solve(board, n);
                            if(isValid) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board, 9); }
};
