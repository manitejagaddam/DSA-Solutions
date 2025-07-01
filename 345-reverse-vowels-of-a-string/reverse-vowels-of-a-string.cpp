class Solution {

private:
    bool isVowel(char & ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() - 1;

        while(start < end){
            while(start < end && !isVowel(s[start])) start++;
            while(start < end && !isVowel(s[end])) end--;
            if(start < end) swap(s[start++], s[end--]);
        }
        
        return s;
    }
};