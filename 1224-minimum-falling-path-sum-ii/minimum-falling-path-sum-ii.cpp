class Solution {

private:
    int ans = INT_MAX;
    vector<vector<int>> dp;

    void dfs(vector<vector<int>> & grid, int row, int col, int sum){
        int row_size = grid.size();
        int col_size = grid[0].size();
        if(row == row_size) {
            ans = min(ans, sum);
            return;
        }
        // if(sum > ans) return;            // this will only work for the positive ellements only
        for(int idx = 0 ; idx < col_size ; idx++){
            if(idx == col) continue;
            dfs(grid, row + 1, idx, sum + grid[row][idx]);
        }
    }


    int memo(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: last row
        if (row == n - 1) return grid[row][col];

        // Return cached value if already computed
        if (dp[row][col] != INT_MAX) return dp[row][col];

        int minPath = INT_MAX;

        // Explore all possible next moves except same column
        for (int nextCol = 0; nextCol < m; ++nextCol) {
            if (nextCol == col) continue;
            int candidate = grid[row][col] + memo(grid, row + 1, nextCol);
            minPath = min(minPath, candidate);
        }

        return dp[row][col] = minPath;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        dp.assign(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int res = INT_MAX;
        for(int idx = 0 ; idx < grid[0].size() ; idx++){
            // dfs(grid, 1, idx, grid[0][idx]);
            res = min(res, memo(grid, 0, idx));
        }
        // return ans;
        return res;
    }
};