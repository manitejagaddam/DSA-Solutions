class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        
        for(int idx = 1 ; idx < len - 1 ; idx++){
            if(nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1]) return idx;
        }
        if(len > 1 && nums[0] > nums[1]) return 0; 
        return len - 1;
    }
};