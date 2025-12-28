class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);
        int len = pref.size();
        int ansXor = pref[0];
        for(int idx = 1 ; idx < len ; idx++){
            ans.push_back(ansXor ^ pref[idx]);
            ansXor ^= ans[idx];
        }
        return ans;
    }
};