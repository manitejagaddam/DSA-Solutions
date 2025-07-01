class Solution {
public:
    int possibleStringCount(string word) {
        // vector<int> mpp(26, 0);
        // for(char ch : word) mpp[ch - 'a']++;
        // int possibleCount = 1;
        // for(int freq : mpp)
        //     if(freq)
        //         possibleCount += freq - 1;
        
        // return possibleCount;

        int possibleCount = 1;
        int len = word.length();
        for(int i = 1 ; i < len ; i++){
            if(word[i] == word[i - 1]) possibleCount++;
        }
        return possibleCount;



    }
};