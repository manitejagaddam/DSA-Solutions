class Solution {

private:    
    int ans = INT_MAX;
    int len = 0;
    string s;


    vector<vector<vector<int>>> dp;
    
    int getIndex(char ch) {
    return (ch == ' ') ? 26 : (ch - 'A');
    }
    
    pair<int, int> getPairValue(char ch){
        return {getIndex(ch) / 6, getIndex(ch) % 6};
    }

    int getCost(char ch1, char ch2){
        if(ch1 == ' ') return 0;
        auto [x1, y1] = getPairValue(ch1);
        auto [x2, y2] = getPairValue(ch2);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    void backtracking(int idx, char finger1, char finger2, int cost1, int cost2){
        if(idx == len) {
            ans = min(ans, cost1 + cost2);
            return;
        }

        backtracking(idx + 1, s[idx], finger2, cost1 + getCost(finger1, s[idx]), cost2);
        backtracking(idx + 1, finger1, s[idx], cost1, cost2 + getCost(finger2, s[idx]));            
    }

    int memoization(int idx, char finger1, char finger2){
        if(idx == len) return 0;
        if(dp[idx][getIndex(finger1)][getIndex(finger2)] != -1) return dp[idx][getIndex(finger1)][getIndex(finger2)];

        int op1 = memoization(idx + 1, s[idx], finger2) + getCost(finger1, s[idx]);
        int op2 = memoization(idx + 1, finger1, s[idx]) + getCost(finger2, s[idx]);

        return dp[idx][getIndex(finger1)][getIndex(finger2)] = min(op1, op2);
    }


public:
    int minimumDistance(string word) {
        s = word;
        len = word.size();
        dp.resize(word.size(), vector<vector<int>>(27, vector<int>(27, -1)));
        // backtracking(0, ' ', ' ', 0, 0);
        // return ans;
        return memoization(0, ' ',  ' ');
    }
};