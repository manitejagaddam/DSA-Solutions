class Solution {
public:
    long long appealSum(string s) {
        // int idx = s.size() - 1;
        // long long ans = 0LL;
        // while(idx >= 0){
        //     unordered_set<int> st;
        //     for(int temp_idx = idx ; temp_idx >= 0 ; temp_idx--){
        //         st.insert(s[temp_idx]);
        //         ans += st.size();
        //     }
        //     idx--;
        // }
        // return ans;
        vector<int> mpp(26, -1);
        long long ans = 0;
        long long curr = 0;
        int len = s.size();
        for(int idx = 0 ; idx < len ; idx++){
            int currIdx = s[idx] - 'a';
            curr += (idx - mpp[currIdx]);
            ans += curr;
            mpp[currIdx] = idx;
        }
        return ans;
    }
};