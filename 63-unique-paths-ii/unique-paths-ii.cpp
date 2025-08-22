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

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1) return 0;
        // return backtrack(obstacleGrid, 0, 0, m, n);

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoization(obstacleGrid, 0, 0, m, n, dp);
    }
};