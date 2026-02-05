class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        for(int idx = 0 ; idx < size ; idx++){
            int temp = (idx + nums[idx]) % size;
            temp = temp < 0 ? temp + size : temp;
            ans.push_back(nums[temp]);
        }
        return ans;
    }
};