class Solution {

private:
    bool isVowel(char ch){

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(char ch : s) {
            if(isVowel(ch)) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());

        string t = "";
        int vowel_idx = 0;
        for(char ch : s){
            if(isVowel(ch)) t += vowels[vowel_idx++];
            else t += ch;
        }

        return t;
    }
};