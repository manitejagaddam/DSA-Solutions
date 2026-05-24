class Solution {

private:
    int memoization(vector<int> & nums, int idx, vector<int> & dp){
        if(idx >= nums.size() - 1) return 0;
        if(dp[idx] != -1) return dp[idx];

        int size {nums[idx]};
        int count {INT_MAX - 1};
        while(size){
            count = min(count, memoization(nums, idx + size, dp) + 1);
            size--;
        }
        return dp[idx] = count;
    }

public:
    int jump(vector<int>& nums) {
        int size {static_cast<int>(nums.size())};
        vector<int> dp(size + 1, {-1});

        return memoization(nums, 0, dp);

    }
};