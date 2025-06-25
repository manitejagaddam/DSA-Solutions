class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int start = 0;
        // int end = nums.size() - 1;
        // int count = nums.size();
        // while(start <= end){
        //     if(nums[start] == val && nums[end] != val){
        //         swap (nums[start], nums[end]);
        //         start++;
        //         end--;
        //         count--;
        //     } else if(nums[end] == val){
        //         end--;
        //         count--;
        //     } else {
        //         start++;
        //     }
        // }
        // return count; 



        // int start = 0;
        // int n = nums.size();
        // int end = n - 1;
        // int count = n;
        // while(start <= end){
        //     if(nums[start] == val && nums[end] != val){
        //         swap(nums[start], nums[end]);
        //         start++;
        //         end--;
        //         count--;
        //     }
        //     else if(nums[end] == val){
        //         end--;
        //         count--;
        //    }else{
        //         start++;
        //     }
        // }
        
        // return count;



        int noe = nums.size();
        int start = 0;
        int end = noe - 1;
        int no_valid_ele = noe;
        while(start <= end){
            if(nums[start] == val && nums[end] != val) {
                swap(nums[start], nums[end]);
                start++;
                end--;
                no_valid_ele--;
            }else if(nums[end] == val){
                end--;
                no_valid_ele--;
            }else{
                start++;
            }
        }

        return no_valid_ele;
        
    }
};