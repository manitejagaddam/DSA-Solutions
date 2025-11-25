class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;
        for(int ele : nums){
            if(ele <= mini1) mini1 = ele;
            else if(ele <= mini2) mini2 = ele;
            else return true; 
        }
        return false;
    }
};