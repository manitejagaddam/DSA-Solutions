class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(int ele : nums){
            if(ele % 2 == 0) count++;
        }
        return count > 1;
    }
};