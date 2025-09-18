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

    int tabulation(vector<int> coins, int amount){
        int n = coins.size();
        const int INF = 1e9; 
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                int not_take = dp[i - 1][j]; 
                int take = INF;

                if (coins[i] <= j)
                    take = 1 + dp[i][j - coins[i]]; 

                dp[i][j] = min(take, not_take);
            }
        }

        return (dp[n - 1][amount] == INF) ? -1 : dp[n - 1][amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        // int ans = memoization(coins, coins.size() - 1, amount, dp);
        // return ans != INT_MAX ? ans : -1;
        return tabulation(coins, amount);
    }
};