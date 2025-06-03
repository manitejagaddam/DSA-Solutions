class Solution {

private:
    int recurssion(vector<vector<int>> grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        if(row == m - 1 && col == n - 1 && grid[row][col] != 1) return 1;
        if(row >= m || col >= n) return 0;

        if(grid[row][col] == 1) return 0;
        
        int down = recurssion(grid, row + 1, col);
        int right = recurssion(grid, row, col + 1);

        return down + right;     


    }

    int memoization(vector<vector<int>> & grid, int row, int col, vector<vector<int>> & dp){
        int m = grid.size();
        int n = grid[0].size();

        if(row == m - 1 && col == n - 1 && grid[row][col] != 1) return 1;

        if(row >= m || col >= n) return 0;

        if(grid[row][col] == 1) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int down  = memoization(grid, row + 1, col, dp);
        int right = memoization(grid, row, col + 1, dp);

        return dp[row][col] = down + right;

    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        // // Brute Force Mthod Recurssion
        // return recurssion(obstacleGrid, 0, 0);

        // Memoization Method
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() , -1));
        return memoization(obstacleGrid, 0, 0, dp);


    }
};