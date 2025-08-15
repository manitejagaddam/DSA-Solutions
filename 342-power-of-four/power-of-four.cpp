class Solution {
public:
    bool isPowerOfFour(int n) {
        // int low = 0;
        // int high = n;
        // while(low <= high){
        //     int mid = (low + high) / 2;
        //     if(pow(4, mid) == n) return true;
        //     else if(pow(4, mid) < n) low = mid + 1;
        //     else high = mid - 1;
        // }
        // return false;

        if(n == 0) return false;
        int odd = 1;
        while (odd < 33) {
            if ( (n & (1 << (odd - 1))) == n )
                return (n & (n - 1)) == 0;
            odd += 2;
        }
        return false;

    }
};