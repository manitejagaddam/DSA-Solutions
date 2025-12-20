class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, bp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] >= nums[i]) bp = i;
            ans = max(ans, i - bp + 1);
        }
        return ans;
    }
};