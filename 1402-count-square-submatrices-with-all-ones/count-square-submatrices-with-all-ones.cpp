class Solution {

private:

    bool isValid(vector<vector<int>> & matrix, int rowStart, int colStart, int side){
        for(int row = rowStart ; row < side + rowStart ; row++){
            for(int col = colStart ; col < colStart + side ; col++){
                if(!matrix[row][col]) return false;
            }
        }
        return true;
    }

    int CountParticularSquareSide(vector<vector<int>> & matrix, int side){
        int squares_count = 0;
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        for(int row = 0 ; row <= rowLen - side ; row++){
            for(int col = 0 ; col <= colLen - side ; col++){
                if(isValid(matrix, row, col, side)) squares_count++;
            }
        }
        return squares_count;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        // int ones_count = 0;
        int squares_count = 0;
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        // for(int row = 0 ; row < rowLen ; row++){
        //     for(int col = 0 ; col < colLen ; col++){
        //         if(matrix[row][col]) ones_count++;
        //     }
        // }

        // squares_count += ones_count;

        for(int side = 1 ; side <= min(rowLen, colLen) ; side++){
            squares_count += CountParticularSquareSide(matrix, side);
        }
        return squares_count;
    }
};