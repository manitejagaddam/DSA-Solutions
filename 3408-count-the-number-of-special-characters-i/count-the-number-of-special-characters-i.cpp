class Solution {
public:
    int numberOfSpecialChars(string word) {
        // unordered_set<char> st(word.begin(), word.end());
        // int count {0};

        // for(char ch : word){
        //     if(ch <= 'z' && st.count(toupper(ch))) count++;
        //     else if(ch <= 'z' && st.count(tolower(ch))) count++;
        // }
        // return count;


        unordered_map<char, int> mpp;
        int count {0};
        for(char ch : word) mpp[ch]++;
        for(auto it : mpp){
            if(it.first <= 'Z' && mpp[tolower(it.first)] > 0) count++;
        }
        return count;
    }
};