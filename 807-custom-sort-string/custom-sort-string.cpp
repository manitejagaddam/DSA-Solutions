class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> order_val;
        int val = 1;
        for(char ch : order) order_val[ch] = val++;
        sort(s.begin(), s.end(), [&](char a, char b){
            int val_a = order_val.count(a) ? order_val[a] : INT_MAX;
            int val_b = order_val.count(b) ? order_val[b] : INT_MAX;
            return val_a < val_b;
        });
        return s;
    }
};