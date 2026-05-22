class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int n {nums.size()};
        int n = nums.size();
        int start {0};
        int end {n - 1};

        while(start <= end){

            int mid {(start + end) / 2};
            cout << nums[start] << " " << nums[mid] << " " << nums[end] << " " << target << endl;
            if(nums[mid] == target)return mid;

            // left sorted
            if(nums[mid] >= nums[start]){
                if(target >= nums[start] && target < nums[mid]){
                    end = mid - 1;
                }else start = mid + 1;
            }

            // right sorted
            else if(nums[mid] < nums[end]){
                if(target > nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }else end = mid - 1;
            }
        }

        return -1;
    }
};