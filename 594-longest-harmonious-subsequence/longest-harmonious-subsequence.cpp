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
    }
};