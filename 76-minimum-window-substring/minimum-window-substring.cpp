class Solution {
public:
    string minWindow(string s, string t) {
        int r = 0, l = 0, idx = 0, count = 0, mini = INT_MAX;
        int n = s.length();
        vector<int> mpp(256, 0);
        for(char i : t) mpp[i]++;
        while(r < n){
            if(mpp[s[r]] > 0){
                count++;
            }
            mpp[s[r]]--;
            while(count == t.length()) {
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    idx = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) count--;
                l++;
            }

            r++;

        }
        return mini == INT_MAX ? "" : s.substr(idx, mini);
    }
};