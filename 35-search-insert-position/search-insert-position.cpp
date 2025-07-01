class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int target = 5;
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        // if(target < nums[start]){
        //     return 0;
        // }
        if(target > nums[end]){
            return nums.size();
        }
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (target == nums[mid])
            {
                return mid;
                // cout << mid <<endl;
            }
            if (target > nums[mid])
            {
                start = mid + 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
        }
        return start;
    }
};