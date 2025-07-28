class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int count = 0;
        int increment = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] <= nums[i - 1]){
                int increased = nums[i - 1] + 1  - nums[i];
                count += increased;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return count;
        

        // int maxi = 0;
        // for(int num : nums){
        //     maxi = max(maxi, num);
        // }
        // int n = nums.size();

        // vector<int> mpp(n + maxi + 1, 0);

        // for(int i : nums){
        //     mpp[i]++;
        // }

        // int ans = 0;

        // for(int i = 0 ; i < n + maxi ; i++){
        //     if(mpp[i] == 1) continue;

        //     int extra = mpp[i] - 1;

        //     mpp[i + 1] += extra;

        //     ans += extra;

        //     mpp[i] = 1;
        // }

        // return ans;



    }
};