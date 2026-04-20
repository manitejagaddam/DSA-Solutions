class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigitSum = 0;
        int doubleDigitSum = 0;
        for(int ele : nums){
            if(ele < 10) singleDigitSum += ele;
            else doubleDigitSum += ele;
        }

        return singleDigitSum != doubleDigitSum;
        
    }
};