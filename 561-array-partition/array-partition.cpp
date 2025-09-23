class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        // for(int ele : nums){
        //     ans += min(ele, ele.next());
        // }
        int len = nums.size();
        for(int idx = 0 ; idx < len ; idx += 2){
            // ans += min(nums[idx], nums[idx + 1]);
            ans += nums[idx];
        }
        return ans;
    }
};