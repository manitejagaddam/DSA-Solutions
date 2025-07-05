class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        int odd = 1;
        while(x >= 0){
            x -= odd;
            odd += 2;
            i++;
        }
        return i - 1;
    }
};