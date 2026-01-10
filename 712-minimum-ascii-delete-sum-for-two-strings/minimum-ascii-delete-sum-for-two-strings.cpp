class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[s1.size() + 1][s2.size() + 1];

        for(int i = 0 ; i <= s1.size() ; i++){
            for(int j = 0 ; j <= s2.size() ; j++){
                if(i == 0 && j == 0) dp[i][j] = 0;
                else if(i == 0) dp[i][j] = dp[i][j - 1] + s2[j - 1];
                else if(j == 0) dp[i][j] = dp[i - 1][j] + s1[i - 1];
                else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        // for(int i = 0 ; i <= s1.size() ; i++){
        //     for(int j = 0 ; j <= s2.size() ; j++){
        //         if(i == 0 && j == 0) dp[i][j] = 0;
        //         else if(i == 0) dp[i][j] = dp[i][j - 1] + s2[j - 1];  // Insertion cost for s2
        //         else if(j == 0) dp[i][j] = dp[i - 1][j] + s1[i - 1];  // Insertion cost for s1
        //         else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1]; // No change needed
        //         else{
        //             dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]); // Choose min of insert or delete
        //         }
        //     }
        // }

        return dp[s1.size()][s2.size()];
        // int dp[s1.length() + 1][s2.length() + 1];
        // for(int i = 0 ; i <= s1.size() ; i++){
        //     for(int j = 0 ; j <= s2.size() ; j++){
        //         if(i == 0){
        //             dp[i][j] = stoi(s1[j]);
        //         }
        //         else if(j == 0){
        //             dp[i][j] = stoi(s2[i]);
        //         }
        //         else if(s1[i - 1] == s2[j - 1]){
        //             dp[i][j] = dp[i - 1][j - 1];
        //         }else{
        //             dp[i][j] = min({dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]}) + 1;
        //         }
        //     }
        // }

        // return dp[s1.size()][s2.size()];
    }
};