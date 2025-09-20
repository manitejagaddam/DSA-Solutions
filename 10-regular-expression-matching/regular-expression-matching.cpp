class Solution {

private:
    string s1, s2;
    int n1, n2;
    vector<vector<int>> dp;
    bool backtracking(int idx1, int idx2){
        if(idx1 == n1 && idx2 == n2) return true;
        if(idx2 == n2) return false;

        // if(s1[idx1] == s2[idx2] || s2[idx2] == '.') op1 = backtracking(idx1 + 1, idx2 + 1);

        // if(s2[idx2] == '*') op2 = backtracking(idx1 + 1, idx2) || backtracking(idx1 + 1, idx2 + 1);

        bool currMatch = idx1 < n1 && (s2[idx2] == '.' || s1[idx1] == s2[idx2]);

        if(idx2 + 1 < n2 && s2[idx2 + 1] == '*'){
            bool exclude = backtracking(idx1, idx2 + 2);
            bool include = false;
            if(currMatch) include = backtracking(idx1 + 1, idx2);
            return include || exclude;
        }else if(currMatch){
            return backtracking(idx1 + 1, idx2 + 2);
        }
        
        return false;
    }

    bool memoization(int idx1, int idx2){
        if(idx1 == n1 && idx2 == n2) return true;
        if(idx2 >= n2) return false;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        bool firstMatch = idx1 < n1 && (s1[idx1] == s2[idx2] || s2[idx2] == '.');

        if(idx2 + 1 < n2 && s2[idx2 + 1] == '*'){
            bool exclude = memoization(idx1, idx2 + 2);
            bool include = false;
            if(firstMatch) include = memoization(idx1 + 1, idx2);
            return dp[idx1][idx2] = include || exclude;
        }else if(firstMatch){
            return dp[idx1][idx2] = memoization(idx1 + 1, idx2 + 1);
        }

        return dp[idx1][idx2] = false;
    }


public:
    bool isMatch(string s, string p) {
        s1 = s;
        s2 = p;
        n1 = s.length();
        n2 = p.length();

        dp.resize(n1 + 1, vector<int>(n2 + 1, -1));
        // return backtracking(0, 0);
        return memoization(0, 0);
    }
};