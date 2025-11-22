class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int ans = 0;
        int prefix = 0;
        for(int ele : nums){
            prefix += (ele % 2) ? 1 : 0;
            if(mpp.count(prefix - k)){
                ans += mpp[prefix - k];
            }
            mpp[prefix]++;
        }
        return ans;
    }
};