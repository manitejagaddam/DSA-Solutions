class Solution {

private:
    bool isVowel(char ch){
        return ch == 'a' ||
               ch == 'e' ||
               ch == 'i' ||
               ch == 'o' ||
               ch == 'u';
    }

public:
    int maxVowels(string s, int k) {
        int maxi = 0;
        int sum = 0;
        for(int idx = 0 ; idx < k ; idx++){
            if(isVowel(s[idx])) maxi++;
        }
        int len = s.length();
        sum = maxi;
        for(int idx = k ; idx < len ; idx++){
            bool first = isVowel(s[idx - k]);
            bool last = isVowel(s[idx]);
            if(first && !last) sum--;
            else if(!first && last) sum++;
            maxi = maxi < sum ? sum : maxi;
        }
        return maxi;
    }
};