class Solution {

private:
    int backtrack(vector<int> & nums, int idx){
        if(idx >= nums.size()) return 0;
        // int sum = 0;
        int pick = nums[idx] + backtrack(nums, idx + 2);
        int notpick = backtrack(nums, idx + 1);

        return max(pick, notpick);
    }

    int memoization(vector<int> & nums, int idx, vector<int> & dp){
        if(idx >= nums.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + memoization(nums, idx + 2, dp);
        int notpick = memoization(nums, idx + 1, dp);

        return dp[idx] = max(pick, notpick);

    }

    int tabulation(vector<int> & nums){
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];       
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // return backtrack(nums, 0);

        vector<int> dp(n, -1);

        return memoization(nums, 0, dp);

        return tabulation(nums);

         
    }
};