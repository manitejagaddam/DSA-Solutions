class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++){
            int setBits = __builtin_popcount(i);
            if(setBits == 2 || setBits == 3 || setBits == 5 || setBits == 7 || 
            setBits == 11 || setBits == 13 || setBits == 17 || setBits == 19 || 
            setBits == 23 || setBits == 29 || setBits == 31)
            {
                count++;
            }
        }
        return count;
    }
};