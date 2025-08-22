class Solution {

private:
    int backtrack(vector<int> & nums, int idx, int sum, int target){
        if(idx < 0){
            if(sum == target) return 1;
            return 0;
        }

        return backtrack(nums, idx - 1, sum + nums[idx], target) + backtrack(nums, idx - 1, sum - nums[idx], target);
    }

    int memoization(vector<int> & nums, int idx, int sum, int target, vector<vector<int>> & dp, int totalSum){
        if(idx < 0){
            if(sum == target) return 1;
            return 0;
        }

        if(dp[idx][totalSum + sum] != INT_MIN) return dp[idx][totalSum + sum];

        return dp[idx][sum + totalSum] = memoization(nums, idx - 1, sum + nums[idx], target, dp, totalSum) + memoization(nums, idx - 1, sum - nums[idx], target, dp, totalSum);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // return backtrack(nums, nums.size() - 1, 0, target);

        int len = nums.size();
        // int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int ele : nums) sum += ele;

        vector<vector<int>> dp(len, vector<int>(2 * sum + 1, INT_MIN));
        return memoization(nums, nums.size() - 1, 0, target, dp, sum);
    }
};