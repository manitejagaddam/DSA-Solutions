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
    int countVowelSubstrings(string word) {
        int len = word.size();
        int ans = 0;
        unordered_set<int> st;
        for(int idx1 = 0 ; idx1 < len ; idx1++){
            for(int idx2 = idx1 ; idx2 < len ; idx2++){
                if(isVowel(word[idx2])) st.insert(word[idx2]);
                else break;
                if(st.size() == 5) ans++;
            }
            st.clear();
        }

        return ans;
    }
};