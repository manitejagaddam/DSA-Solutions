class Solution {

private:
    int backtrack(vector<int> & nums, int idx){
        if(idx >= nums.size() - 1) return 0;

        int temp_idx = nums[idx];
        int ans = INT_MAX - 1;
        while(temp_idx){
            ans = min(ans, backtrack(nums, idx + temp_idx) + 1); 
            temp_idx--;
        }
        return ans;
    }

    int memoization(vector<int> & nums, int idx, vector<int> & dp){
        if(idx >= nums.size() - 1) return 0;

        if(dp[idx] != -1) return dp[idx];
        int temp_idx = nums[idx];
        int ans = INT_MAX - 1;

        while(temp_idx) {
            ans = min(ans, memoization(nums, idx + temp_idx, dp)  + 1);
            temp_idx--;
        }
        return dp[idx] = ans;
    }

public:
    int jump(vector<int>& nums) {

        // // BackTracking
        // int idx = 0;
        // return backtrack(nums, idx);

        // Memoization
        int idx = 0;
        vector<int> dp(nums.size(), -1);

        return memoization(nums, idx, dp);



        
        // // Greedy Approach

        // int n = nums.size();
        // if(n == 1) return 0;

        // int jump = 0;
        // int end = 0;
        // int far = 0;
        // for(int i = 0 ; i < n ; i++){
        //     far = max(far, i + nums[i]);

        //     if(i == end){
        //         jump++;
        //         end = far;
        //         if(end >= n - 1) return jump;
        //     }
        // }

        // return jump;
        
    }
};