class Solution {

private:
    int isValid(int s1, int s2, int s3){
        return s1 + s2 > s3 && s2 + s3 > s1 && s3 + s1 > s2;
    }

public:
    int largestPerimeter(vector<int>& nums) {
        int perimeter = 0;
        int len = nums.size();
        // for(int s1 = 0 ; s1 < len - 2 ; s1++){
        //     for(int s2 = s1 + 1 ; s2 < len - 1 ; s2++){
        //         for(int s3 = s2 + 1 ; s3 < len ; s3++){
        //             if(isValid(nums[s1], nums[s2], nums[s3])) 
        //                 perimeter = max(perimeter, (nums[s1] + nums[s2] + nums[s3]));
        //         }
        //     }
        // }
        sort(nums.begin(), nums.end());
        // for(int s1 = len - 1 ; s1 >= 0 ; s1--){
        //     for(int s2 = s1 - 1 ; s2 >= 0 ; s2--){
        //         for(int s3 = s2 - 1 ; s3 >= 0 ; s3--){
        //             if(isValid(nums[s1], nums[s2], nums[s3])) return nums[s1] + nums[s2] + nums[s3];
        //         }
        //     }
        // }

        int s1 = len - 1 ; 
        int s2 = len - 2;
        int s3 = len - 3;
        while(s3 >= 0){
            if(isValid(nums[s1], nums[s2], nums[s3])) return nums[s1] + nums[s2] + nums[s3];
            s1--;
            s2--;
            s3--;
        }

        return perimeter;
    }
};