class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int ele : nums) sum += ele;
        return sum % k;
    }
};