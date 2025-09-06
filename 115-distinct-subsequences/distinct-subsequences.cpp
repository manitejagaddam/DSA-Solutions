class Solution {

private:
    int MOD = 1e9 + 7;
    int backtracking(string & s, string & t, int idx1, int idx2){
        if(idx2 < 0) return 1;
        if(idx1 < 0) return 0;

        if(s[idx1] == t[idx2])
            return backtracking(s, t, idx1 - 1, idx2 - 1) + backtracking(s, t, idx1 - 1, idx2);

        return backtracking(s, t, idx1 - 1, idx2);
    }
    
    
    int memoization(string & s, string & t, int idx1, int idx2, vector<vector<int>> & dp){
        if(idx2 < 0) return 1;
        if(idx1 < 0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s[idx1] == t[idx2])
            return dp[idx1][idx2] = memoization(s, t, idx1 - 1, idx2 - 1, dp) + memoization(s, t, idx1 - 1, idx2, dp);

        return dp[idx1][idx2] = memoization(s, t, idx1 - 1, idx2, dp);
    }

    int tabulation(string & s, string & t){
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for(int idx = 0 ; idx <= s.size(); idx++) dp[idx][0] = 1;

        for(int idx1 = 1 ; idx1 <= s.size() ; idx1++){
            for(int idx2 = 1 ; idx2 <= t.size() ; idx2++){
                if(s[idx1 - 1] == t[idx2 - 1]) dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] % MOD + dp[idx1 - 1][idx2] % MOD;
                else dp[idx1][idx2]= dp[idx1 - 1][idx2];
            }
        }

        return dp[s.size()][t.size()];
    }



public:
    int numDistinct(string s, string t) {
        // return backtracking(s, t, s.size() - 1, t.size() - 1);
        // vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        // return memoization(s, t, s.size() - 1, t.size() - 1, dp);

        return tabulation(s, t);

    }
};