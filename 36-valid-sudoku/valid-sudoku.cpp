class Solution {

private:
    bool isValid(vector<vector<char>> & board, int row, int col){
        for(int i = 0 ; i < 9 ; i++){
            if(i == row) continue;
            if(board[i][col] == board[row][col]) return false;
        }

        for(int i = 0 ; i < 9 ; i++){
            if(i == col) continue;
            if(board[row][i] == board[row][col]) return false;
        }

        int subr = (row / 3) * 3;
        int subc = (col / 3) * 3;

        for(int i = subr ; i < subr + 3 ; i++){
            for(int j = subc ; j < subc + 3 ; j++){
                if(i == row && j == col) continue;
                if(board[i][j] == board[row][col]) return false;
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0 ; row < 9 ; row++){
            for(int col = 0 ; col < 9 ; col++){
                if(board[row][col] != '.' && !isValid(board, row, col)) return false;
            }
        }

        return true;
    }
};