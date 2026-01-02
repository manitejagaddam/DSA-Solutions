class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int oddOne = 0;
        int len = nums.size();
        for(int idx = 1 ; idx < len ; idx++){
            if(nums[idx] < nums[idx - 1]){
                oddOne++;
                if(oddOne > 1) return false;
                
                if(idx == 1 || nums[idx] >= nums[idx - 2]){
                    nums[idx - 1] = nums[idx];  
                } else {
                    nums[idx] = nums[idx - 1];  
                }
            }
        }
        return oddOne < 2;
    }
};