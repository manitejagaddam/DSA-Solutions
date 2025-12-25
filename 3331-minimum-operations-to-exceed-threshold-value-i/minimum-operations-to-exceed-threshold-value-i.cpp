class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for(int ele : nums) 
            if(ele < k) count++;
        return count;
    }
};