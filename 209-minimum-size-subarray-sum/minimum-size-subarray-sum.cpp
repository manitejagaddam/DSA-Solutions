class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int noe = nums.size();
        int start = 0;
        int end = 0;
        int sum = 0;
        int minLen = nums.size() + 1;
        while(end < noe){
           sum += nums[end++];
           while(sum >= target){
            minLen = minLen > end - start ? end - start : minLen;
            sum-= nums[start++];
           }
            // cout << start << " " << end << " -> " << sum << endl;
        }
        return minLen < nums.size() + 1 ? minLen : 0;
    }
};