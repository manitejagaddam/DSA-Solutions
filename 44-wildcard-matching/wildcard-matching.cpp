class Solution {

private:
    bool backtrack(string s, string p, int sIdx, int pIdx){
        if(sIdx == s.length() && pIdx == p.length()) return true;
        else if(pIdx == p.length()) return false;   //case where pattern is done but string is not completed
        
        else if(sIdx < s.length() && (s[sIdx] == p[pIdx] || p[pIdx] == '?')){
            return backtrack(s, p, sIdx + 1, pIdx + 1);
        }else if(p[pIdx] == '*'){
            return (sIdx < s.length() && backtrack(s, p, sIdx + 1, pIdx)) || backtrack(s, p, sIdx, pIdx + 1);
        }
        return false;
    }

    bool memoization(string & s, string & p, int sIdx, int pIdx, vector<vector<int>> & dp){

        if(dp[sIdx][pIdx] != -1) return dp[sIdx][pIdx] == 1 ? true : false;

        bool res;
        
        if(sIdx == s.length() && pIdx == p.length()) res = true;
        else if(pIdx == p.length()) res = false;   //case where pattern is done but string is not completed
        
        else if(sIdx < s.length() && (s[sIdx] == p[pIdx] || p[pIdx] == '?')){
            res = memoization(s, p, sIdx + 1, pIdx + 1, dp);
        }else if(p[pIdx] == '*'){
            res = (sIdx < s.length() && memoization(s, p, sIdx + 1, pIdx, dp)) || memoization(s, p, sIdx, pIdx + 1, dp);
        }else{
            res = false;
        }
        
        dp[sIdx][pIdx] = res ? 1 : 0;
        return res;
    }

public:
    bool isMatch(string s, string p) {
        // return backtrack(s, p, 0, 0);


        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return memoization(s, p, 0, 0, dp);
    }
};