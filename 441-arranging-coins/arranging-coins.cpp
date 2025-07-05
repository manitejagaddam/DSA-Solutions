class Solution {
public:
    int arrangeCoins(int n) {
        long long ans = 1;
        int count = 1;
        for(int i = 2 ; i < n ; i++){
            ans += i;
            if(ans > n) return count;
            count++;
        }
        return count;
        
    }
};