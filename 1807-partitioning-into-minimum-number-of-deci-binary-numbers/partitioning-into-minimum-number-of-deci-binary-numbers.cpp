class Solution {

private:
    int maxDigit(string s){
        int maxNum = 0;
        for(char ch : s){
            maxNum = max(maxNum, ch - '0');
        }
        return maxNum;
    }

public:
    int minPartitions(string n) {
        return maxDigit(n);
    }
};