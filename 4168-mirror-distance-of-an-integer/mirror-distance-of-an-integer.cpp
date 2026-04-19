class Solution {

private:
    int reverseNumber(int n){
        int tempNum = 0;
        while(n){
            tempNum *= 10;
            tempNum += n % 10;
            n /= 10;
        }
        // cout << tempNum;
        return tempNum;
    }

public:
    int mirrorDistance(int n) {
        return abs(n - reverseNumber(n));
    }
};