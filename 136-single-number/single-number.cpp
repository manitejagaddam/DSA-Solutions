class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        for(int ele : nums) singleNum ^= ele;
        return singleNum;
    }
};