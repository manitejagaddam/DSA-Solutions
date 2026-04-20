class Solution {
public:
    int alternateDigitSum(int n) {
        // if(n < 10) return n;
        int len = (int)log10(n) + 1;
        int sign = 1;
        if(len % 2 == 0) sign = -1;
        cout << (int)log10(n) << " " << len;
        int sum = 0;
        while(n){
            sum += (n % 10) * sign;
            sign *= -1;
            n /= 10;
        }
        return sum;
    }
};