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

    int tabulation(vector<vector<int>> & grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int row = 1 ; row < m ; row++) dp[row][0] += dp[row - 1][0] + grid[row][0];
        for(int col = 1 ; col < n ; col++) dp[0][col] += dp[0][col - 1] + grid[0][col];

        for(int row = 1 ; row < m ; row++){
            for(int col = 1 ; col < n ; col++){
                dp[row][col] = grid[row][col] + min(dp[row - 1][col], dp[row][col - 1]);
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++) cout << dp[i][j] << " ";
            cout << endl;
        }

        return dp[m - 1][n - 1];

    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // return backtrack(grid, 0, 0, m, n);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(grid, 0, 0, m, n, dp);

        return tabulation(grid);
    }
};