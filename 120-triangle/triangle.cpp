class Solution {

private:
    int recurssion(vector<vector<int>> & grid, int row, int col, int m){
        int n = grid[row].size();
        if(col >= n) return INT_MAX;

        if(row == m - 1) return grid[row][col];
        
        int down = grid[row][col] + recurssion(grid, row + 1, col, m);
        int diagonal = grid[row][col] + recurssion(grid, row + 1, col + 1, m);

        return min(down, diagonal);
    }

    int memoization(vector<vector<int>> & grid, int row, int col, vector<vector<int>> & dp){
        int m = grid.size();
        // int n = grid[row].size();
        int n = grid[row].size();

        if(col >= n) return INT_MAX;

        if(row == m - 1) return grid[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        int down = grid[row][col] + memoization(grid, row + 1, col, dp);
        int diagonal = grid[row][col] + memoization(grid, row + 1, col + 1, dp);

        return dp[row][col] = min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        // // Recurssion Brute Force Method
        // return recurssion(triangle, 0, 0, triangle.size());

        // Memoization Optimal
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        return memoization(triangle, 0, 0, dp);
    }
};