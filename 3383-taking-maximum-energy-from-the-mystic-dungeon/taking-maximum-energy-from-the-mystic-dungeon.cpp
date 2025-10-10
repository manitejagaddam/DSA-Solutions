class Solution {

private:
    int len, kVal;
    vector<long long> dp;

    long long memoization(vector<int> & nums, int idx){
        if(idx >= len) return 0;
        if(dp[idx] != LLONG_MIN) return dp[idx];

        return dp[idx] = nums[idx] + memoization(nums, idx + kVal);
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
        dp.resize(len, LLONG_MIN);
        long long ans = INT_MIN;

        for(int idx = 0 ; idx < len ; idx++){
            ans = max(ans, memoization(energy, idx));
        }
        return (int)ans;
    }
};