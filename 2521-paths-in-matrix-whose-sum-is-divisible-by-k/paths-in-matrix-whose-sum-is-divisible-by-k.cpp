class Solution {

private:
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;
    int row_len, col_len;

    int backtrack(vector<vector<int>> & grid, int row, int col, int sum, int k){
        if(row == row_len || col == col_len) return 0;
        if(row == row_len - 1 && col == col_len - 1) {
            if((sum + grid[row][col]) % k == 0) return 1;
            return 0;
        }
        if(dp[row][col][sum % k] != -1) return dp[row][col][sum % k];
        int ans = 0;
        ans += (backtrack(grid, row + 1, col, sum + grid[row][col], k)) % MOD;
        ans += (backtrack(grid, row, col + 1, sum + grid[row][col], k)) % MOD;

        return dp[row][col][sum % k] = ans % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        row_len = m;
        col_len = n;
        dp.resize(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return backtrack(grid, 0, 0, 0, k);
    }
};