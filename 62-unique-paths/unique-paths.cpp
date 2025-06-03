class Solution {

private:
    int recurssion(int row, int col, int row_end, int col_end){
        if(row == row_end - 1 && col == col_end - 1) return 1;
        if(row >= row_end || col >= col_end) return 0;
        int right = recurssion(row + 1, col, row_end, col_end);
        int down = recurssion(row, col + 1, row_end, col_end);

        return right + down;
    
    }
    
    
    int memoization(int row, int col, int row_end, int col_end, vector<vector<int>> & dp){
        if(row == row_end - 1 && col == col_end - 1) return 1;
        if(row >= row_end || col >= col_end) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int right = recurssion(row + 1, col, row_end, col_end);
        int down = recurssion(row, col + 1, row_end, col_end);

        return dp[row][col] = right + down;
    }

    int tabulation(int row_end, int col_end){
        vector<vector<int>> dp(row_end + 1, vector<int>(col_end + 1, 0));
        
        dp[row_end][col_end] = 1;
        for(int i = row_end ; i >= 0 ; i--){
            for(int j = col_end ; j >= 0 ; j--){
                if (i + 1 <= row_end) dp[i][j] += dp[i + 1][j]; 
                if (j + 1 <= col_end) dp[i][j] += dp[i][j + 1];
            }
        }

        return dp[0][0];
    }


public:

    // int countPaths(int i, int j, int m, int n){
    //     if((i == (m - 1)) && (j == (n - 1))) return 1;
    //     else if((i >=(m)) || (j >= (n))) return 0;
    //     else return countPaths(i+1, j, m, n) + countPaths(i, j+1, m, n);
    // }

    // int countPathsDp(int i, int j, int m, int n, vector<vector<int>> &dp){
    //     if((i == m - 1) && (j == n - 1)) return 1;
    //     else if(i >= m || j >= n) return 0;
    //     else if(dp[i][j] != -1) return dp[i][j];
    //     else return dp[i][j] = countPathsDp(i+1, j, m, n, dp) + countPathsDp(i, j + 1, m, n, dp);

    // }


    

    int uniquePaths(int m, int n) {
        // return countPaths(0,0,m,n);
        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        // return countPathsDp(0,0,m,n,dp);

        // return recurssion(0, 0, m, n);


        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, - 1));

        // return memoization(0, 0, m, n, dp);


        // Tabulation
        return tabulation(m - 1,n - 1);


        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        // return solve(0, 0, m, n, dp);




        // int N = n + m - 2;
        //     int r = m - 1; 
        //     double res = 1;
        //     int down = 1;
        //     int up = N;
        //     for (int i = 1; i <= r; i++)
        //         res = res * (N - r + i) / i;
        //     // for(int i = 1; i <= r; i++){
        //     //     res *= up--;
        //     //     res /= i;
        //     // }
        //     return (int)res;
    }
};