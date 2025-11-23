class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int start = 0;
        int end = 0;
        int ans = 0;
        while(end < len){
            if(nums[end] == 0) k--;
            if(k < 0){
                if(nums[start] == 0) k++;
                start++;
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};