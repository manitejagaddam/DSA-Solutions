class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int mini = len +1;
        int start = 0;
        int end = 0;
        int sum = 0;
        while(end < len){
            sum += nums[end];
            while(sum >= target){
                mini = min(mini, end - start + 1);
                sum -= nums[start++];
            } 
            end++;
        }
        return mini != len + 1 ? mini : 0;
    }
};