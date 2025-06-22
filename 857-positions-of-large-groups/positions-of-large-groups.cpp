class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int noc = s.length(); // no of characters
        int start = 0; 
        int end = 0;
        vector<vector<int>> ans;
        for(end = 0 ; end < noc ; end++){
            char first_char = s[start];
            while(s[end] == s[start]) end++;
            if(end - start >= 3) ans.push_back({start, end - 1});
            start = end; 
        }
        return ans;
    }
};