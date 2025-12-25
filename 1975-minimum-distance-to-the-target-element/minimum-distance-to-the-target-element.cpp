class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int len = nums.size();
        int mini = INT_MAX;
        for(int idx = 0 ; idx < len ; idx++){
            if(nums[idx] == target) mini = min(mini, abs(idx - start));
        }
        return mini;
    }
};