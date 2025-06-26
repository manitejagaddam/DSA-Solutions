class Solution {

private:
    bool backtrack(vector<int> & nums, int idx){
        if(idx >= nums.size() - 1) return true;

        int temp_idx = nums[idx];
        while(temp_idx){
            if(backtrack(nums, idx + temp_idx)) return true;
            temp_idx--;
        }
        return false;
    }

    bool memoization(vector<int> & nums, int idx, vector<int> & dp){
        if(idx >= nums.size() - 1) return true;
        if(dp[idx] != -1) return dp[idx];

        int temp_idx = nums[idx];

        while(temp_idx){
            if(memoization(nums, idx + temp_idx, dp)) return dp[idx] = 1;
            temp_idx--;
        }

        return dp[idx] = 0;
    }


public:
    bool canJump(vector<int>& nums) {

        // // Backtracking
        // return backtrack(nums, 0);


        // Memoiation
        vector<int> dp(nums.size() + 1, -1);
        return memoization(nums, 0, dp);
    }
};