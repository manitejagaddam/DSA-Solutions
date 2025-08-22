class Solution {

private:
    int backtrack(vector<vector<int>> & grid, int row, int col, int m, int n){
        if(row == m - 1 && col == n - 1) return 1;
        if(row == m || col == n) return 0;
        if(grid[row][col] == 1) return 0;

        int ans = backtrack(grid, row + 1, col, m, n) + backtrack(grid, row, col + 1, m, n);

        return ans;
    }

    int memoization(vector<vector<int>> & grid, int row, int col, int m, int n, vector<vector<int>> & dp){
        if(row == m - 1 && col == n - 1) return 1;
        if(row == m || col == n) return 0;
        if(grid[row][col] == 1) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = memoization(grid, row + 1, col, m, n, dp) + memoization(grid, row, col + 1, m, n, dp);
    }

    int tabulation(vector<vector<int>> & grid, int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (grid[0][0] == 1) return 0;

        dp[0][0] = 1; 

        for (int row = 1; row < m; row++) {
            if (grid[row][0] == 0 && dp[row-1][0] == 1) {
                dp[row][0] = 1;
            } else {
                dp[row][0] = 0; 
            }
        }

        for (int col = 1; col < n; col++) {
            if (grid[0][col] == 0 && dp[0][col-1] == 1) {
                dp[0][col] = 1;
            } else {
                dp[0][col] = 0; 
            }
        }

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                if (grid[row][col] == 1) {
                    dp[row][col] = 0; 
                } else {
                    dp[row][col] = dp[row-1][col] + dp[row][col-1];
                }
            }
        }

        return dp[m-1][n-1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1) return 0;
        // return backtrack(obstacleGrid, 0, 0, m, n);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(obstacleGrid, 0, 0, m, n, dp);

        return tabulation(obstacleGrid, m, n);
    }
};