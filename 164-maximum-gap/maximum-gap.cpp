class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans = 0;
        for(int idx =  1 ; idx < len ; idx++){
            ans = ans < nums[idx] - nums[idx - 1] ? nums[idx] - nums[idx - 1] : ans;
        }   
        return ans;
    }
};