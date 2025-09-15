class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // unordered_set<char> st(brokenLetters.begin(), beokenLetters.end());
        unordered_set<char> st;
        for(char ch : brokenLetters) st.insert(ch);
        int len = text.size();
        int no_words = 0;
        int no_broken_words = 0;
        for(int idx = 0 ; idx < len ; idx++){
            bool found_faulty = false;
            while(idx < len && text[idx] != ' '){
                if(st.find(text[idx++]) != st.end()) {
                    if(!found_faulty) {
                        no_broken_words++;
                        found_faulty = true;
                    }
                }
            }
            no_words++;
        }
        return no_words - no_broken_words;
    }
};