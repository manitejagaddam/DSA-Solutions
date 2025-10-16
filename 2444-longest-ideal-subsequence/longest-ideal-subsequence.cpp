class Solution {

private:
    
    vector<vector<int>> dp;

    // BACKTRACK FUNCTION
    int backtrack(string & s, int idx, char prevChar, int k){
        if(idx < 0) return 0; // ISSUE: backward recursion base case. Fine here, but inconsistent with memoization.

        int pick = 0;
        int notpick = 0;

        // BUG: commented code shows you tried starting character logic
        // if(prevChar == '#') pick = 1 + backtrack(s, idx + 1, s[idx], k);
        // else{
        //     if(abs(prevChar - s[idx]) <= k) pick = 1 + backtrack(s, idx + 1, s[idx], k);
        //     else notpick = backtrack(s, idx + 1, prevChar, k);
        // }

        // BUG: using backward recursion, idx-1, but logic mixed with forward recursion later
        if(abs(prevChar - s[idx]) <= k) pick = 1 + backtrack(s, idx - 1, s[idx], k);
        else notpick = backtrack(s, idx - 1, prevChar, k);

        cout << s << " " << idx << " " << pick << " " << notpick << endl;

        return max(pick, notpick);
    }

    // MEMOIZATION FUNCTION
    int memoization(string & s, int idx, char prevChar, int k){
        if(idx == s.size()) return 0; // OK: forward recursion base case

        // BUG: prevChar is a char, DP indexed as dp[idx][prevChar] 
        // - can go negative (if using '#') or >256
        // - undefined behavior
        if(dp[idx][prevChar] != -1) return dp[idx][prevChar];

        int pick = 0;
        int notpick = 0;

        // BUG: commented starting character logic is incomplete
        // if(prevChar == '#'){
        //     pick = 1 + memoization(s, idx - 1, s[idx], k);
        //     notpick = memoization(s, idx - 1, prevChar, k);
        // } 
        
        // BUG 1: using += inflates values
        if(prevChar == '#' || abs(prevChar - s[idx]) <= k){
            pick += 1 + memoization(s, idx + 1, s[idx], k); // ISSUE: should be '=' not '+='
        }
            notpick += memoization(s, idx + 1, prevChar, k); // ISSUE: '+=' inflates result, also inconsistent

        // cout << s << " " << idx << " " << pick << " " << notpick << endl;

        // BUG 2: DP index could be invalid if prevChar not in 0-255
        return dp[idx][prevChar] = max(pick, notpick);
    }


public:
    int longestIdealString(string s, int k) {
        int len = s.size();

        // BUG 3: dp.resize(len, vector<int>(256, -1)) → 256 may not cover '#' or sentinel char, too large
        dp.resize(len, vector<int>(256, -1));

        // BUG 4: starting at idx=1, prevChar = s[0], forces inclusion of first character
        // This skips subsequences that might skip s[0]
        // return memoization(s, 1, s[0], k) + 1; 
        return memoization(s, 0, '#', k);
    }
};
