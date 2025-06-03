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


    int tabulation(vector<vector<int>> & grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        dp[0][0] = grid[0][0];

         for(int j = 1; j < n; j++){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];

    }


    int tabulation_space_optimized(vector<vector<int>> & grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, INT_MAX);
        prev[0] = 0;

        for(int i = 0 ; i < m ; i++){
            vector<int> curr(n);
            for(int j = 0 ; j < n ; j++){
                if(j == 0) curr[j] = grid[i][j] + prev[j];
                else curr[j] = min(curr[j - 1], prev[j]) + grid[i][j];
            }
            prev = curr;
        }

        return prev[n - 1];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        // // BReute Force Method Recurssion
        // return recurssion(grid, 0, 0);

        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // return memoization(grid, 0, 0, dp);

        // return tabulation(grid);
        
        return tabulation_space_optimized(grid);
    }
};