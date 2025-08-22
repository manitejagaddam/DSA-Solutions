class Solution {

private:
    int backtrack(vector<vector<int>> & triangle, int row, int col, int size){
        if(row == size - 1) return triangle[row][col];
        if(row == size) return INT_MAX;

        
        return triangle[row][col] + min(backtrack(triangle, row + 1, col, size), backtrack(triangle, row + 1, col + 1, size));
    }

    int memoization(vector<vector<int>> & triangle, int row, int col, int size, vector<vector<int>> & dp){
        if(row == size - 1) return triangle[row][col];
        if(row == size) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];
        
        return triangle[row][col] + min(memoization(triangle, row + 1, col, size, dp), memoization(triangle, row + 1, col + 1, size, dp));
    }

    int tabulation(vector<vector<int>> & triangle){
        int m = triangle.size();
        vector<vector<int>> dp(m);
        for(int i = 0 ; i < m ; i++){
            dp[i] = vector<int>(i + 1, 0);
        }

        for(int col = 0 ; col < m ; col++){
            dp[m - 1][col] = triangle[m - 1][col];
        }
        
        for(int row = m - 2 ; row >= 0 ; row--){
            for(int col = 0 ; col <= row ; col++){
                dp[row][col] = triangle[row][col] + min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }

        return dp[0][0];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // return backtrack(triangle, 0, 0, m);

        // vector<vector<int>> dp(m);
        // for (int i = 0; i < m; i++) {
        //     dp[i] = vector<int>(i + 1, -1);
        // }
        // return memoization(triangle, 0, 0, m, dp);

        return tabulation(triangle);

    }
};