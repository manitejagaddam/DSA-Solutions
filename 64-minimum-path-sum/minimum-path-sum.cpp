class Solution {

private:
    int backtrack(vector<vector<int>> & grid, int row, int col, int m, int n){
        if(row == m - 1 && col == n - 1) return grid[row][col];
        if(row == m || col == n) return INT_MAX;

        return grid[row][col] + min(backtrack(grid, row + 1, col, m, n), backtrack(grid, row, col + 1, m, n));
    }

    int memoization(vector<vector<int>> & grid, int row, int col, int m, int n, vector<vector<int>> & dp){
        if(row == m - 1 && col == n - 1) return grid[row][col];
        if(row == m || col == n) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = grid[row][col] + min(memoization(grid, row + 1, col, m, n, dp), memoization(grid, row, col + 1, m, n, dp));
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // return backtrack(grid, 0, 0, m, n);

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoization(grid, 0, 0, m, n, dp);
    }
};