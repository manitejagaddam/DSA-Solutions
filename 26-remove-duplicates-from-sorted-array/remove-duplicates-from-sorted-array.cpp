class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int noe = nums.size();
        int unique_idx = 1;
        int no_uniques = 1;
        for(int idx = 1 ; idx < noe ; idx++){
            if(nums[idx] != nums[idx - 1]) {
                nums[unique_idx++] = nums[idx];
                no_uniques++;    
            } 
        }
        return no_uniques;
        
    }
};