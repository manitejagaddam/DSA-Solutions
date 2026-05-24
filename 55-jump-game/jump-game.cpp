class Solution {

private:
    bool recurrsion(vector<int> & nums, int idx){
        if(idx >= nums.size() - 1) return true;
        bool ans {false};
        for(int temp_idx = idx + 1 ; temp_idx <= idx + nums[idx] ; temp_idx++ ){
            if(recurrsion(nums, temp_idx)) {
                ans = true;
                return true;
            }
        }
        return ans;
    }

    bool memoization(vector<int> & nums, int idx, vector<int> & dp){
        if(idx >= nums.size() - 1) return true;
        if(dp[idx] != -1) return dp[idx] == 1;
        bool ans {false};
        for(int temp_idx = idx + 1 ; temp_idx <= nums[idx] + idx; temp_idx++){
            if(memoization(nums, temp_idx, dp)) {
                ans = true;
                dp[idx] = 1;
                return true;
            }
        }
        dp[idx] = ans == true ? 1 : 0;
        return ans;
    }

public:
    bool canJump(vector<int>& nums) {
        // return recurrsion(nums, 0);
        int size {static_cast<int>(nums.size())};
        vector<int> dp(size + 1, {-1});
        return memoization(nums, 0, dp);

    }
};