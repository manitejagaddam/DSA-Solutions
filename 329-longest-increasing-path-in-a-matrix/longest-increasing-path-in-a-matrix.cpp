class Solution {

private:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>> & grid, int row, int col, int m, int n, vector<vector<int>> & dp){
        if(dp[row][col] != -1) return dp[row][col];
        

        int ans = 1;
        for(auto [dx, dy] : dir){
            int nr = row + dx;
            int nc = col + dy;
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] > grid[row][col]) {
                ans = max(ans, 1 + dfs(grid, nr, nc, m, n, dp));
            }
        }
        return dp[row][col] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                ans = max(ans, dfs(matrix, row, col, m, n, dp));
            }
        }

        // return backtrack()
        return ans;
    }
};