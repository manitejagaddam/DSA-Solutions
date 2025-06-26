class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int noe = nums.size();
        // int unique_idx = 1;
        // int no_uniques = 1;
        // int similar_count = 1;
        // vector<int> ans(noe);
        // ans[0] = nums[0];
        // int idx;
        // for(idx = 1 ; idx < noe - 1 ; idx++){
        //     if(nums[idx] != nums[idx - 1])
        //     {
        //         if(similar_count <= 2){
        //             nums[unique_idx++] = nums[idx];
        //             no_uniques++;
        //             similar_count++;
        //         }
        //     }else if(nums[idx + 1] != nums[idx] && similar_count <= 2){

        //         if(similar_count <= 2){
        //             nums[unique_idx++] = nums[idx];
        //             no_uniques++;
        //             similar_count++;
        //         }
        //     }

        // }
        // if(nums[idx] == nums[idx - 1] && nums[idx] != nums[idx - 2]) {
        //     nums[unique_idx] = nums[idx];
        //     no_uniques++;    
        // }

        // return no_uniques;



        int noe = nums.size();
        int idx = 2;
        if(noe <= 2) return noe;
        for(int i = 2 ; i < noe ; i++){
            if(nums[i] != nums[idx - 2]) {
                nums[idx++] = nums[i];
            }
        }

        return idx;
    }
};