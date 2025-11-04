class Solution {
public:
    int smallestNumber(int n) {
        int no_bits = 0;
        while(n > 0){
            no_bits++;
            n >>= 1;
        }

        // cout << no_bits << " ";
        // cout << (1 << no_bits - 1);
        return (1 << no_bits) - 1;
    }
};