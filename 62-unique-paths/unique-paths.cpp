class Solution {

private:
    int backtrack(int row, int col, int m, int n){
        if(row == m - 1 && col == n - 1) return 1;
        if(row == m || col == n) return 0;

        int ans = 0;
        ans += backtrack(row + 1, col, m, n);
        ans += backtrack(row, col + 1, m, n);

        return ans;

    }

    int memoization(int row, int col, int m, int n, vector<vector<int>> & dp){
        if(row == m - 1 && col == n - 1) return 1;
        if(row == m || col == n) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int ans = 0;
        ans += backtrack(row + 1, col, m, n);
        ans += backtrack(row, col + 1, m, n);

        return ans;
    }

    int tabulation(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int row = 0 ; row < m ; row++) dp[row][0] = 1;
        for(int col = 0 ; col < n ; col++) dp[0][col] = 1;

        for(int row = 1 ; row < m ; row++){
            for(int col = 1 ; col < n ; col++){
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    int combinations(int m, int n){
        // Allowed moves: only DOWN or RIGHT

        // Total moves = (m - 1) downs + (n - 1) rights
        int steps = (m - 1) + (n - 1);   // total steps needed (m - 1) + (n - 1)
        int r = min(m - 1, n - 1); // choose the smaller one for efficiency

        // We need to compute C(steps, r) = steps! / (r! * (steps-r)!)
        // Instead of factorials, we use the multiplicative formula
        long long ans = 1; // use long long to avoid overflow in intermediate steps

        for (int i = 1; i <= r; i++) {
            // Multiply by (steps - r + i) and divide by i at each step
            ans = ans * (steps - r + i) / i;
        }

        return (int)ans; // final result always fits into int for given constraints
    }


public:
    int uniquePaths(int m, int n) {
        // return backtrack(0, 0, m, n);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(0, 0, m, n, dp);

        // return tabulation(m, n);

        return combinations(m, n);
    }
};