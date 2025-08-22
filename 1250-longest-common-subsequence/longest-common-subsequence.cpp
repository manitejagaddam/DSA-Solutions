class Solution {

private:
    int backtrack(string s1, string s2, int idx1, int idx2){
        if(idx1 < 0 || idx2 < 0) return 0;

        if(s1[idx1] == s2[idx2]) return 1 + backtrack(s1, s2, idx1 - 1, idx2 - 1);
        return max(backtrack(s1, s2, idx1 - 1, idx2), backtrack(s1, s2, idx1, idx2 - 1));
    }

    int memoization(string & s1, string & s2, int idx1, int idx2, vector<vector<int>> & dp){
        if(idx1 < 0 || idx2 < 0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s1[idx1] == s2[idx2]) return dp[idx1][idx2] = 1 + memoization(s1, s2, idx1 - 1, idx2 - 1, dp);
        return dp[idx1][idx2] = max(memoization(s1, s2, idx1 - 1, idx2, dp),
                                    memoization(s1, s2, idx1, idx2 - 1, dp));
    }

    int tabulation(string & s1, string & s2){
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int idx1 = 1 ; idx1 <= m ; idx1++){
            for(int idx2 = 1 ; idx2 <= n ; idx2++){
                if(s1[idx1 - 1] == s2[idx2 - 1]) dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }

        return dp[m][n];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int idx1 = text1.length() - 1;
        int idx2 = text2.length() - 1;

        // return backtrack(text1, text2, idx1, idx2);
        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        // return memoization(text1, text2, idx1, idx2, dp);

        return tabulation(text1, text2);
    }
};