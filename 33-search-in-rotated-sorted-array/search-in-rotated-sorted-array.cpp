class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0;
        int end = len - 1;
        while(start <= end){
            int mid = (start + end) / 2;
    // 		cout << "start : " << start << " end : " << end << endl;
            if(nums[mid] == target) return mid;
            
            
            // left half is sorted
            else if(nums[mid] >= nums[start]){
                // eliminating the right half
            if(nums[mid] > target && nums[start] <= target){
                    end = mid - 1;
                }else start = mid + 1;
            }
            // right half is sorted
            else{
                if(nums[mid]  < target && nums[end] >= target){
                    start = mid + 1;			
                }else end = mid - 1;
            }
        }

        return -1;
    }
};