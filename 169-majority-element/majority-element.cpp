class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // BETTER APPROACH

        // unordered_map<int, int> mpp;
        // for(int i : nums) mpp[i]++;
        // int n = nums.size();

        // for(auto i : mpp){
        //     if(i.second > n / 2) return i.first;
        // }
        // return -1;



        
        // OPTIMAL APPROACH

        // int element = nums[0];
        // int count = 0;
        // for(int i : nums){
        //     if(count == 0){
        //         element = i;
        //     }
        //     if(i == element){
        //         count++;
        //     }else{
        //         count--;
        //     }
        // }
        // return element;


        vector<int> stack(nums.size(), 0);
        int i=0;
        for(int x:nums){
            if(i == 0){
                stack[i]=x;
                i++;
            }
            else if(stack[i-1] ==  x){
                stack[i]=x;
                i++;
            }
            else{
                i--;
            }
        }
        return stack[i-1];

    }
};