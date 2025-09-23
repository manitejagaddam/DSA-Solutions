class Solution {

private:
    bool isVowel(char ch){
        return ch == 'a' ||
               ch == 'e' ||
               ch == 'i' ||
               ch == 'o' ||
               ch == 'u';
    }

    int vowelIdx(char ch){
        switch(ch){
            case 'a' : return 0;
            case 'e' : return 1;
            case 'i' : return 2;
            case 'o' : return 3;
            case 'u' : return 4;
        }
        return -1;
    }

public:
    int countVowelSubstrings(string word) {
        // int len = word.size();
        // int ans = 0;
        // unordered_set<int> st;
        // for(int idx1 = 0 ; idx1 < len ; idx1++){
        //     for(int idx2 = idx1 ; idx2 < len ; idx2++){
        //         if(isVowel(word[idx2])) st.insert(word[idx2]);
        //         else break;
        //         if(st.size() == 5) ans++;
        //     }
        //     st.clear();
        // }

        // return ans;

        int ans = 0;
        int len = word.size();

        for(int idx1 = 0 ; idx1 < len ;){
            if(!isVowel(word[idx1])) {
                idx1++;
                continue;
            }

            int idx2 = idx1;
            while(idx2 < len && isVowel(word[idx2])) idx2++;

            vector<int> freq(5, 0);
            int distinct = 0;
            int left = idx1;

            for(int right = idx1 ; right < idx2 ; right++){
                int idx = vowelIdx(word[right]);
                if(freq[idx] == 0) distinct++;
                freq[idx]++;

                while(distinct == 5){
                    ans += (idx2 - right);
                    int leftIdx = vowelIdx(word[left]);
                    freq[leftIdx]--;
                    if(!freq[leftIdx]) distinct--;
                    left++;
                }
            }
            idx1 = idx2;
        }

        return ans;


    }
};