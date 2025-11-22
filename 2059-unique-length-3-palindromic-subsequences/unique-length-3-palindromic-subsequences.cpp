class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        int len = s.length();
        for(int idx = 0 ; idx < len ; idx++){
            int ch = s[idx] - 'a';
            if(first[ch] == -1) first[ch] = idx;
            last[ch] = idx;
        }

        int palindromeCount = 0;
        unordered_set<char> st;
        for(int idx = 0 ; idx < 26 ; idx++){
            int first_idx = first[idx];
            int last_idx = last[idx];
            if(first_idx == -1 || last_idx - first_idx < 2) continue;

            for(int temp_idx = first_idx + 1; temp_idx < last_idx ; temp_idx++){
                st.insert(s[temp_idx]);
            }

            palindromeCount += st.size();
            st.clear();
        }
        return palindromeCount;
    }
};