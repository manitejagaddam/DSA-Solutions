class Solution {

private:

    bool backtrack(vector<int> & nums, int idx, int tempSum, int target){
        if(idx < 0) return false;
        if(tempSum > target) return false;
        if(tempSum == target) return true;
        return backtrack(nums, idx - 1, tempSum, target) || backtrack(nums, idx - 1, tempSum + nums[idx], target);
    }

    bool memoization(vector<int> & nums, int idx, int tempSum, int target, vector<vector<int>> & dp){
        if(idx < 0) return false;
        if(tempSum > target) return false;
        if(tempSum == target) return true;

        if(dp[idx][tempSum] != -1) return dp[idx][tempSum];

        return dp[idx][tempSum] = memoization(nums, idx - 1, tempSum, target, dp) || memoization(nums, idx - 1, tempSum + nums[idx], target, dp);
    }

public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int ele : nums) sum += ele;
        if(sum % 2) return false;

        int target = sum / 2;

        // return backtrack(nums, nums.size() - 1, 0, target);
        vector<vector<int>> dp(len, vector<int>(target + 1, -1));
        return memoization(nums, nums.size() - 1, 0, target, dp);

    }
};