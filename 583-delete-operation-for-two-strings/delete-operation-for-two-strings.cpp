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

public:
    int minDistance(string word1, string word2) {
        // return word1.length() + word2.length() - 2 * LCS(word1, word2);
        int lcs = LCS(word1, word2);
        return word1.length() - lcs + word2.length() - lcs;
    }
};