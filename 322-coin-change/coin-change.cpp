class Solution {

private:
    int memoization(vector<int> & coins, int idx, int amount, vector<vector<int>> & dp){
        if(amount == 0) return 0;
        if(amount < 0 || idx < 0) return INT_MAX;
        if(dp[idx][amount] != -1) return dp[idx][amount];

        // return dp[idx][amount] = min(memoization(coins, idx, amount - coins[idx], dp), memoization(coins, idx - 1, amount, dp)) + 1;
        int take = memoization(coins, idx, amount - coins[idx], dp);
        int notTake = memoization(coins, idx - 1, amount, dp);
        if(take != INT_MAX) take++;
        return dp[idx][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = memoization(coins, coins.size() - 1, amount, dp);
        return ans != INT_MAX ? ans : -1;
    }
};