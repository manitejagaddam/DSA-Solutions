class Solution {

private:
    bool isPalindrome(string s){
        int start = 0 ;
        int end = s.length() - 1;
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }


    string BaseConverter(int n, int base){
        string s = "";

        while(n){
            s += n % base;
            n /= base;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    bool isStrictlyPalindromic(int n) {
        for(int base = 2 ; base <= n - 2 ; base++){
            if(!isPalindrome(BaseConverter(n, base))) return false;
        }
        return true;
    }
};