class Solution {
public:
    string customSortString(string order, string s) {
       

        // Using the Map Data Structure
        unordered_map<char, int> mpp;
        for(char ch : s) mpp[ch]++;

        string ans = "";

        for(char ch : order){

            int size = mpp[ch];
            ans += string (size, ch);
            mpp.erase(ch);
        }

        for(auto it : mpp){
            ans += string(it.second, it.first);
        }

        return ans;


       

        // // Using Sort Lambda Functions
        // unordered_map<char, int> order_val;
        // int val = 1;
        // for(char ch : order) order_val[ch] = val++;
        // sort(s.begin(), s.end(), [&](char a, char b){
        //     int val_a = order_val.count(a) ? order_val[a] : INT_MAX;
        //     int val_b = order_val.count(b) ? order_val[b] : INT_MAX;
        //     return val_a < val_b;
        // });
        // return s;
    }
};