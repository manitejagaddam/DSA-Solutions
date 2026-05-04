class Solution {

private:
    int m, n;
    int dfs(vector<vector<int>> & grid, int row, int col, int cost, int k){
        if(row == m - 1 && col == n - 1){
            if(grid[row][col] > 0 && k == 0) return -1;
            return cost + grid[row][col];
        }
        if(row == m || col == n) return -1;
        k = grid[row][col] > 0 ? k - 1 : k;

        return max(dfs(grid, row + 1, col, cost + grid[row][col], k), 
                   dfs(grid, row, col + 1, cost + grid[row][col], k));
    }

    int memoization(vector<vector<int>> & grid, int row, int col, int k, vector<vector<vector<int>>> & dp){
        if(row >= m || col >= n) return -1e9;

        if(grid[row][col]) k--;

        if(k < 0) return -1e9;

        if(row == m - 1 && col == n - 1) return grid[row][col];

        if(dp[row][col][k] != -1) return dp[row][col][k];

        int down = memoization(grid, row, col + 1, k, dp);
        int right = memoization(grid, row + 1, col, k, dp);

        int bestPath = max(down, right);

        if(bestPath <= -1e8) return dp[row][col][k] = -1e9;

        return dp[row][col][k] = bestPath + grid[row][col];


    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        
        // return dfs(grid, 0, 0, 0, k);

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = memoization(grid, 0, 0, k, dp);

        return ans <= -1e8 ? -1 : ans;

    }
};