class Solution {
public:
    bool isPowerOfFour(int n) {
        int low = 0;
        int high = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(pow(4, mid) == n) return true;
            else if(pow(4, mid) < n) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};