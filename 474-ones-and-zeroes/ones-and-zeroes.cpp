#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<vector<int>>> dp;  

    pair<int, int> getZeroAndOnesCount(const string &s) {
        int zeroCount = 0, oneCount = 0;
        for (char ch : s) {
            if (ch == '0') zeroCount++;
            else oneCount++;
        }
        return {zeroCount, oneCount};
    }

    int solve(vector<pair<int,int>> &counts, int idx, int m, int n) {
        if (idx == counts.size() || (m == 0 && n == 0))
            return 0;
        if (dp[idx][m][n] != -1)
            return dp[idx][m][n];

        int zeroCount = counts[idx].first;
        int oneCount = counts[idx].second;
        int skip = solve(counts, idx + 1, m, n);
        int take = 0;
        if (m >= zeroCount && n >= oneCount)
            take = 1 + solve(counts, idx + 1, m - zeroCount, n - oneCount);
        return dp[idx][m][n] = max(take, skip);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> counts;
        for (auto &s : strs)
            counts.push_back(getZeroAndOnesCount(s));
        dp.assign(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(counts, 0, m, n);
    }
};
