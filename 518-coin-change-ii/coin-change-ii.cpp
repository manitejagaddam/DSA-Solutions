class Solution {

private:
    int backtrack(vector<int> & coins, int idx, int sum, int amount){
        if(idx < 0) return 0;
        if(sum == amount) return 1;
        if(sum > amount) return 0;

        return backtrack(coins, idx, sum + coins[idx], amount) + backtrack(coins, idx - 1, sum, amount);
    }

    int memoization(vector<int> & coins, int idx, int sum, int amount, vector<vector<int>> & dp){
        if(idx < 0) return 0;
        if(sum == amount) return 1;
        if(sum > amount) return 0;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];

        return dp[idx][sum] = memoization(coins, idx, sum + coins[idx], amount, dp) + memoization(coins, idx - 1, sum, amount, dp);

    }

public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        // return backtrack(coins, len - 1, 0, amount);

        int sum = accumulate(coins.begin(), coins.end(), 0);
        vector<vector<int>> dp(len, vector<int>(amount + 1, -1));

        return memoization(coins, len - 1, 0, amount, dp);
    }
};