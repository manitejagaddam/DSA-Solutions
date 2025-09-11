class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(int ele : nums){
            if(ele % 2 == 0) {
                count++;
                if(count > 1) return true;
            }
        }
        return false;
    }
};