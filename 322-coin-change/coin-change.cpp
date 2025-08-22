class Solution {

private:
    int backtrack(vector<int> & coins, int idx, int tempSum, int count, int target){
        if(tempSum == target) return count;
        if(tempSum > target) return INT_MAX;
        if(idx < 0) return INT_MAX;
        return min(backtrack(coins, idx, tempSum + coins[idx], count + 1, target), backtrack(coins, idx - 1, tempSum, count, target));
    }

    int memoization(vector<int>& coins, int idx, int tempSum, int target, vector<vector<int>>& dp) {
        if (tempSum == target) return 0;            
        if (tempSum > target) return INT_MAX;       
        if (idx < 0) return INT_MAX;                

        if (dp[idx][tempSum] != -1) return dp[idx][tempSum];

        int take = memoization(coins, idx, tempSum + coins[idx], target, dp);
        if (take != INT_MAX) take += 1; 

        int skip = memoization(coins, idx - 1, tempSum, target, dp);

        return dp[idx][tempSum] = min(take, skip);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        sort(coins.begin(), coins.end());
        int len = coins.size();
        // int ans = backtrack(coins, coins.size() - 1, 0, 0, amount);

        vector<vector<int>> dp(len, vector<int>(amount + 1, -1));
        int ans = memoization(coins, coins.size() - 1, 0, amount, dp);

        return ans != INT_MAX ? ans : -1;
    }
};