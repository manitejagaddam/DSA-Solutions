class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        for(int ele : nums) mini = mini > ele ? ele : mini;
        return mini;
    }
};