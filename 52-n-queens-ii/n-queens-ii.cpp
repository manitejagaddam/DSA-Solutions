class Solution {

private:

    bool isSafe(vector<vector<int>> & grid, int row, int col){
        int n = grid.size();
        if(row == 0) return true;

        // UP Check
        for(int i = 0 ; i < row ; i++) 
            if(grid[i][col]) 
                return false;
        
        // LEFT DIAGONAL Check
        for(int i = row, j = col ; i >= 0 && j >= 0 ; i--, j--)
            if(grid[i][j]) 
                return false;
        
        // RIGHT DIAGONAL Check
        for(int i = row, j = col ; i >= 0 && j < n ; i--, j++)
            if(grid[i][j])
                return false;
        
        return true;
    }

    void nQueenTraversal(vector<vector<int>> & grid, int row, int & validCount){
        if(row == grid.size()) {
            validCount++;
            return;
        }

        for(int col = 0 ; col < grid.size() ; col++){
            if(isSafe(grid, row, col)){
                grid[row][col] = 1;
                nQueenTraversal(grid, row + 1, validCount);
                grid[row][col] = 0; 
            }
        }
    }

    int countPossibilites(int n){
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int validCount = 0;
        int currRow = 0;
        nQueenTraversal(grid, currRow, validCount);
        return validCount;
    }

public:
    int totalNQueens(int n) {
        return countPossibilites(n);
    }
};