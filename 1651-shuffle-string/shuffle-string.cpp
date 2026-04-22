class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int len = indices.size();
        for(int idx = 0 ; idx < len ; idx++){
            ans[indices[idx]] = s[idx];
        }
        return ans;
    }
};