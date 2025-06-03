class Solution {

private:
    int recurssion(vector<int> & nums, int idx, bool first_pick){
        if(idx >= nums.size()) return 0;
        int pick = 0, notpick = 0;
        notpick = recurssion(nums, idx + 1, first_pick);
        if(idx == 0) first_pick = true;
        if(first_pick && idx == nums.size() - 1) pick = 0; 
        else pick = nums[idx] + recurssion(nums, idx + 2, first_pick);

        return max(pick, notpick);
    }

    int memoization(vector<int> & nums, int idx, bool first_pick, vector<vector<int>> & dp){
        if(idx >= nums.size()) return 0;

        if(dp[idx][first_pick] != -1) return dp[idx][first_pick];

        int pick = 0;
        int notpick = 0;
        
        notpick = memoization(nums, idx + 1, first_pick, dp);
        if(idx == 0) first_pick = true;
        if(first_pick && idx == nums.size() - 1) pick = 0;
        else pick = nums[idx] + memoization(nums, idx + 2, first_pick, dp);

        dp[idx][first_pick] = max(pick, notpick);

        return dp[idx][first_pick];
    }

public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        // // Brute Force Method
        // return recurssion(nums, 0, false);

        // // Memoization Method
        // vector<int> dp(nums.size(), -1);
        vector<vector<int>> dp(nums.size(), vector<int> (2, -1));
        return memoization(nums, 0, false, dp);
    }
};