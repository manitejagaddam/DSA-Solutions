class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        vector<int> mpp(256, -1);
        int start = 0;
        int end = 0;
        int ans = 0;
        while(end < len){
            if(mpp[s[end]] != -1){
                if(start <= mpp[s[end]]) start = mpp[s[end]] + 1;
            }
            mpp[s[end]] = end;
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};