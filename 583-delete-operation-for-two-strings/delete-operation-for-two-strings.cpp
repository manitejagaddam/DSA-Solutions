class Solution {

private:
    int LCS(string & s1, string & s2){
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for(int i = 1 ; i <= len1 ; i++){
            for(int j = 1 ; j <= len2 ; j++){
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[len1][len2];
    }

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

public:
    int minDistance(string word1, string word2) {
        // return word1.length() + word2.length() - 2 * LCS(word1, word2);
        
        // int lcs = LCS(word1, word2);

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        int lcs = memoization(word1, word2, word1.size() - 1, word2.size() - 1, dp);
        
        return word1.length() - lcs + word2.length() - lcs;
    }
};