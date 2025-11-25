class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // unordered_map<char, int> mpp1, mpp2;
        // for(char ch : word1) mpp1[ch]++;
        // for(char ch : word2) mpp2[ch]++;
        // unordered_map<int, int> count_mpp;
        // for(auto it : mpp1){
        //     count_mpp[it.second]++;
        // }
        // for(auto it : mpp2){
        //     count_mpp[it.second]--;
        // }
        // for(auto it : count_mpp){
        //     if(it.second) return false;
        // }
        // return true;



        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;

    }
};