class Solution {

private:

    bool isValid(int n){
        bool reversed = false;
        while(n){

            int digit = n % 10;
            if(digit == 3 || digit == 4 || digit == 7) return false;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) reversed = true;
            n /= 10;
            
        }

        return reversed ;
    }

public:
    int rotatedDigits(int n) {

        int count = 0;
        for(int idx = 1 ; idx <= n ; idx++) {
            if(isValid(idx)) count++;
        }
        return count;
    }
};