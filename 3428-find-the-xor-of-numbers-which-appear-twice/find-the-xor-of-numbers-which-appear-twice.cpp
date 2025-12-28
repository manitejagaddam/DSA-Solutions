class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> mpp(51, 0);
        for(int ele : nums) mpp[ele]++;
        int ans = 0;
        for(int idx = 0 ; idx < 51 ; idx++){
            if(mpp[idx] == 2) ans ^= idx;
        }
        return ans;
    }
};