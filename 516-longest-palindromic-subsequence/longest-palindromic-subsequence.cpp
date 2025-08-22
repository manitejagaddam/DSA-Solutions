class Solution {

private:
    int LCS(string & s1, string & s2){
        int len1 = s1.length();
        int len2 = s2.length();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for(int idx1 = 1 ; idx1 <= len1 ; idx1++){
            for(int idx2 = 1 ; idx2 <= len2 ; idx2++){
                if(s1[idx1 - 1] == s2[idx2 - 1]) dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
        return dp[len1][len2];
    }

public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        return LCS(s, s2);
    }
};