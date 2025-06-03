class Solution {

private:
    int recurssion(vector<vector<int>> & grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        if(row == m - 1 && col == n - 1) return grid[m - 1][n - 1];
        if(row >= m || col >= n) return INT_MAX;

        int down = recurssion(grid, row + 1, col);
        int right = recurssion(grid, row, col + 1); 

        return grid[row][col] +  min(down, right);
    }

    int memoization(vector<vector<int>> & grid, int row, int col, vector<vector<int>> & dp){
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m || col >= n) return INT_MAX;

        if(row == m - 1 && col == n - 1) return grid[m - 1][n - 1];

        if(dp[row][col] != -1) return dp[row][col];

        int down = memoization(grid, row + 1, col, dp);
        int right = memoization(grid, row, col + 1, dp);

        return dp[row][col] = grid[row][col] + min(down, right);


    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        // // BReute Force Method Recurssion
        // return recurssion(grid, 0, 0);

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return memoization(grid, 0, 0, dp);
    }
};