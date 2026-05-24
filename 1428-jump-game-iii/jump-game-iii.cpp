class Solution {

private:
    bool memoization(vector<int> & arr, int idx, vector<int> &dp){
        if(idx < 0 || idx >= arr.size()) return false;
        if(arr[idx] == 0) return true;
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = 0;

        bool ans = memoization(arr, idx + arr[idx], dp) || memoization(arr, idx - arr[idx], dp);
        return dp[idx] = ans;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int size {static_cast<int>(arr.size())};
        vector<int> dp(size + 1, {-1});

        return memoization(arr, start, dp);
        
    }
};