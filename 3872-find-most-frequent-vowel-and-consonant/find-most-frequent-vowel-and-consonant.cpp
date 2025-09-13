class Solution {

private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    int maxFreqSum(string s) {
        vector<int> mpp(26, 0);
        for(char ch : s) mpp[ch - 'a']++;
        int vowel_count = 0;
        int consonent_count = 0;
        for(int idx = 0 ; idx < 26 ; idx++){
            if(isVowel(idx + 'a')) vowel_count = vowel_count < mpp[idx] ? mpp[idx] : vowel_count;
            else consonent_count = consonent_count < mpp[idx] ? mpp[idx] : consonent_count;
        }

        return vowel_count + consonent_count;
    }
};