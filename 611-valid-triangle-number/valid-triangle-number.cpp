class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int count = 0;

        for (int p3 = len - 1; p3 >= 2; p3--) {
            int p1 = 0;
            int p2 = p3 - 1;

            while (p1 < p2) {
                if (nums[p1] + nums[p2] > nums[p3]) {
                    count += (p2 - p1);
                    p2--; 
                } else {
                    p1++; 
                }
            }
        }
        return count;
    }
};
