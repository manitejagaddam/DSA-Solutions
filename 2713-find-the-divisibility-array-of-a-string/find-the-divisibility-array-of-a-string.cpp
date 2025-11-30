class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int len = word.length();
        vector<int> ans(len, 0);
        long long sum = 0;
        int idx = 0;
        for(char ch : word){
            sum = sum * 10;
            sum += ch - '0';
            sum = sum % m;
            if(sum == 0) ans[idx] = 1;
            idx++;
        }
        return ans;
    }
};