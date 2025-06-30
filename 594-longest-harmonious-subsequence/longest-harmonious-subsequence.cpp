class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i : nums) mpp[i]++;
        int maxLen = 0;
        for(auto it : mpp){
            int num = it.first;
            if(mpp.find(num + 1) != mpp.end()) maxLen = maxLen < mpp[num] + mpp[num + 1] ? mpp[num] + mpp[num + 1] : maxLen;
        }
        return maxLen;


        // unordered_map<int, int> mpp;
        // for(int i : nums){
        //     mpp[i]++;
        //     mpp[i + 1]++;
        // }
        // if(mpp.size() == 2) return 0;
        // int maxLen = 0;
        // for(auto it : mpp){
        //     maxLen = maxLen < it.second ? it.second : maxLen;
        // }
        // return maxLen > 1 ? maxLen : 0;
    }
};