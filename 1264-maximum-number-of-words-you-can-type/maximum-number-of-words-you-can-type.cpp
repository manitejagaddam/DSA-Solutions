class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // unordered_set<char> st(brokenLetters.begin(), beokenLetters.end());

        // USING THE SET DATA STRUTURE 
        // TIME COMPLEXITY -> O(N)
        // SPACE COMPLEXITY -> O(N)

        // unordered_set<char> st;
        // for(char ch : brokenLetters) st.insert(ch);
        // int len = text.size();
        // int no_words = 0;
        // int no_brokenWorrds = 0;
        // for(int idx = 0 ; idx < len ; idx++){
        //     bool found_faulty = false;
        //     while(idx < len && text[idx] != ' '){
        //         if(st.find(text[idx++]) != st.end()) {
        //             if(!found_faulty) {
        //                 no_brokenWorrds++;
        //                 found_faulty = true;
        //             }
        //         }
        //     }
        //     no_words++;
        // }
        // return no_words - no_brokenWorrds;








        // USING BIT MANIPULATION
        // TIME COMPLEXITY -> O(N)
        // SPACE COMPLEXITY -> O(1)


        int mask = 0;
        for(char ch : brokenLetters) mask |= (1 << (ch - 'a'));

        int no_words = 0;
        int no_brokenWorrds = 0;
        int len = text.size();
        for(int idx = 0 ; idx < len ; idx++){
            bool foundFaulty = false;
            while(idx < len && text[idx] != ' '){
                if(1 << (text[idx++] - 'a') & mask) {
                    if(!foundFaulty){
                        no_brokenWorrds++;
                        foundFaulty = true;
                    }
                }
            }
            no_words++;
        }

        return no_words - no_brokenWorrds;


    }
};