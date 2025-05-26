class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int i = 0;
        // int num = 0;
        // while(n > 1 ){
        //     if(n % 2 == 0){
        //         n /= 2;
        //     }else{
        //         return false;
        //     }
        // }

        // BIT MANUPLATION
        if(n <= 0){
            return false;
        }
        if ((n & n - 1) == 0) return true;
        return false;
    }
};