class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int sum = 0;
        for(char ch : s) sum += (ch == '0' ? 0 : 1);
        int len = s.length();
        int zeros = len - sum;
        string ans = "";
        for(int idx = 0 ; idx < sum - 1 ; idx++) ans += "1";
        for(int idx = 0 ; idx < zeros ; idx++) ans += "0";
        ans += "1";
        return ans;
    }
};