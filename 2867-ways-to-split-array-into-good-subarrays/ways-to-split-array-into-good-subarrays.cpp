class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1, MOD= 1e9 + 7, count  = 0;
        int i = 0;
        while(i < nums.size() && nums[i] == 0) ++i;
        if(i >= nums.size() ) return 0;
        while(i < nums.size()){
            if(nums[i] == 1){
                ans = (ans * (count + 1))  % MOD;
                count = 0; 
            }
            else count++;
            i++;
        }
        return ans;
    }
};