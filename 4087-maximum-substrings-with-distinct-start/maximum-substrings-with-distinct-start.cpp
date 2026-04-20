class Solution {
public:
    int maxDistinct(string s) {
        // unordered_set<char> st(s.begin(), s.end());
        // return st.size();
        vector<int> freq(27, 0);
        for(char ch : s)
            freq[ch - 'a'] = 1;

        return accumulate(freq.begin(), freq.end(), 0);
    }
};