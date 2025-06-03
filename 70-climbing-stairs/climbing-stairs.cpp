class Solution {

private:
    int memoization(int n, vector<int> & dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = memoization(n - 1, dp) + memoization(n - 2, dp);
    }

    int tabulation(int n){

        if(n <= 3) return n;

        int curr = 0;
        int prev = 2;
        int prev2 = 3;
        for(int i = 4 ; i <= n ; i++){
            curr = prev + prev2;
            prev = prev2;
            prev2 = curr;
        }
        return curr;

    }


    int reccursion(int n){

        if(n == 0) return 1;
        if(n == 1) return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
        
    }
    
    int solve(int n, vector<int> & dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp); 
    }

public:
    int climbStairs(int n) {

        // if(n == 0 || n == 1) return 1;
        // return climbStairs(n - 1) + climbStairs(n - 2);

        vector<int> dp(n + 1, -1);
        return solve(n, dp);

        // return memoization(n, dp);
        // return tabulation(n);


    }
};