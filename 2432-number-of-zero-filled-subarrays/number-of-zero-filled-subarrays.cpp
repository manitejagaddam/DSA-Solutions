class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long count_val = 1;
        int len = nums.size();
        for(int idx = 0 ; idx < len ; idx++){
            if(nums[idx] == 0){
                count += count_val++;
            }else{
                count_val = 1;
            }
        }
        return count;
    }
};