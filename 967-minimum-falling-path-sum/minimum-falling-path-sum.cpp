class Solution {

private:

    int backtrack_helper(vector<vector<int>> & grid, int row, int col, int m, int n){
        if(col < 0 || col == n) return INT_MAX; 
        if(row == m - 1) return grid[row][col];

        return grid[row][col] + min({backtrack_helper(grid, row + 1, col - 1, m, n), backtrack_helper(grid, row + 1, col, m, n), backtrack_helper(grid, row + 1, col + 1, m, n)});
    }

    int backtrack(vector<vector<int>> & grid){
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        for(int col = 0 ; col < n ; col++) ans = min(ans, backtrack_helper(grid, 0, col, m, n));

        return ans;
    }

    int memo_helper(vector<vector<int>> & grid, int row, int col, int m, int n, vector<vector<int>> & dp){
        if(col < 0 || col == n) return INT_MAX; 
        if(row == m - 1) return grid[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = grid[row][col] + min({memo_helper(grid, row + 1, col - 1, m, n, dp), memo_helper(grid, row + 1, col, m, n, dp), memo_helper(grid, row + 1, col + 1, m, n, dp)});
    }


    int memoization(vector<vector<int>> & grid){
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int col = 0 ; col < n ; col++) ans = min(ans, memo_helper(grid, 0, col, m, n, dp));

        return ans;
    }

    int tabulation(vector<vector<int>> & grid){
        int m = grid.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        for(int col = 0 ; col < m ; col++) dp[0][col] = grid[0][col];
        
        for(int row = 1 ; row < m ; row++){
            for(int col = 0 ; col < m ; col++){
                int res = INT_MAX;
                if(col > 0) res = min(res, dp[row - 1][col - 1]);
                if(col < m - 1) res = min(res, dp[row - 1][col + 1]);
                res = min(res, dp[row - 1][col]);
                dp[row][col] = grid[row][col] + res;
            }
        }

        int ans = INT_MAX;
        for(int col = 0 ; col < m ; col++) ans = ans > dp[m - 1][col] ? dp[m - 1][col] : ans;
        return ans;
    }

      

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // return backtrack(matrix);

        // return memoization(matrix);
        return tabulation(matrix);

    }
};