class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0;
        int zero_idx = 0;
        int product = 1;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == 0) {
                zero_count++;
                zero_idx = i;
            }else product *= nums[i];
        }
        vector<int> ans(nums.size(), 0);
        if(zero_count > 1) return ans;
        if(zero_count){
            ans[zero_idx] = product;
        }else{
            for(int i = 0 ; i < nums.size() ; i++){
                ans[i] = product / nums[i];
            }
        }
        return ans;
    }
};