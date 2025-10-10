class Solution {

private:
    int len, kVal;
    vector<int> dp;

    int memoization(vector<int> & nums, int idx){
        if(idx >= len) return 0;
        if(dp[idx] != -1000) return dp[idx];

        return dp[idx] = nums[idx] + memoization(nums, idx + kVal);
    }

    int tabulation(vector<int> & nums){
        int ans = -1000;

        for(int idx = len - 1 ; idx >= 0 ; idx--){
            dp[idx] = nums[idx];
            if(idx + kVal < len){
                dp[idx] += dp[idx + kVal];
            }
            ans = max(ans, dp[idx]);
        }

        return ans;

    }

public:
    int maximumEnergy(vector<int>& energy, int k) {
        // int maxEnergy = INT_MIN;
        // int len = energy.size();
        // for(int start = 0 ; start <= len - k ; start++){
        //     int tempEnergy = 0;
        //     int it = start;
        //     while(it < len){
        //         tempEnergy += energy[it];
        //         it += k;
        //     }
        //     maxEnergy = maxEnergy < tempEnergy ? tempEnergy : maxEnergy;
        // }

        // return maxEnergy;

        len = energy.size();
        kVal = k;
        dp.resize(len, -1000);
        // int ans = INT_MIN;

        // for(int idx = 0 ; idx < len ; idx++){
        //     ans = max(ans, memoization(energy, idx));
        // }
        // return (int)ans;

        return tabulation(energy);
    }
};