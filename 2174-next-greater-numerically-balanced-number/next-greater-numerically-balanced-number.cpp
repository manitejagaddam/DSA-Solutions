class Solution {

private:
    bool isBalanced(int n){
        vector<int> digits(10, 0);
        while(n){
            digits[n % 10]++;
            n /= 10;
        }

        for(int idx = 0 ; idx < 10 ; idx++){
            if(digits[idx] != 0 && digits[idx] != idx) return false;
        }
        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        n++;
        while(true){
            if(isBalanced(n)){
                return n;
            } 
            n++;
        }
        return -1;
    }
};