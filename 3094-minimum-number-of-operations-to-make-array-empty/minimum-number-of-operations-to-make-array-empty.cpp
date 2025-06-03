class Solution {

private:
    
    int combinations(int val, vector<int> & dp){
        if(val < 0) return INT_MAX;
        if(val == 0) return 0;

        if(dp[val] != -1) return dp[val];

        int two = combinations(val - 2, dp);
        int three = combinations(val - 3, dp);
        
        int res = INT_MAX;

        if (two != INT_MAX) res = min(two + 1, res);
        if(three != INT_MAX) res = min(three + 1, res);


        return dp[val] = res;
    }

public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i : nums) mpp[i]++;
        int count = 0;
        for(auto it : mpp){
            int val = it.second;
            vector<int> dp(val + 1, -1);
            int count_val = combinations(val, dp);
            if(count_val == INT_MAX) return -1;
            count += count_val;           
        }
        return count;
    }
};