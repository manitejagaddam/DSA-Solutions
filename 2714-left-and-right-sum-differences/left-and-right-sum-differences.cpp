class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int len {static_cast<int>(nums.size())};
        vector<int> leftSum(len, 0);
        vector<int> rightSum(len, 0);
        for(int idx = 1 ; idx < len ; idx++){
            leftSum[idx] += leftSum[idx - 1] + nums[idx - 1];
        }

        for(int idx = len - 2 ; idx >= 0 ; idx--){
            rightSum[idx] += rightSum[idx + 1] + nums[idx + 1];
        }

        vector<int> ans(len, 0);
        for(int idx = 0 ; idx < len ; idx++){
            ans[idx] = abs(leftSum[idx] - rightSum[idx]);
        }

        return ans;
    }
};