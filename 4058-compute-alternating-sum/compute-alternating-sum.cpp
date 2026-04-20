class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sign = 1;
        int sum =  0;
        for(int ele : nums){
            sum += ele * sign;
            sign *= -1;
        }
        return sum;
    }
};