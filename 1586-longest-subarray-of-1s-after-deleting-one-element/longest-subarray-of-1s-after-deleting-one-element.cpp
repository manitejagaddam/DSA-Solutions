class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = nums.size();
        int left = 0, maxLen = 0;
        int zero = 0;

        for (int right = 0; right < len; right++) {
            if (nums[right] == 0) zero++;

            while (zero > 1) {
                if (nums[left] == 0) zero--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen - 1;
    }
};
