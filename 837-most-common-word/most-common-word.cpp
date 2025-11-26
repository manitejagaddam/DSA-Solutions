class Solution {

private:

    char toLowerChar(char ch) {
        if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
        return ch;
    }

    bool isAlpha(char ch) {
        ch = toLowerChar(ch);
        return (ch >= 'a' && ch <= 'z');
    }

    string normalize(string &s) {
        string ans = "";
        for (char ch : s) {
            if (isAlpha(ch)) ans += toLowerChar(ch);
            else ans += ' ';   
        }
        return ans;
    }

    void splitWords(string &s, vector<string> &words) {
        string temp = "";
        for (char ch : s) {
            if (ch == ' ') {
                if (temp.size() > 0) words.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        if (temp.size() > 0) words.push_back(temp);  
    }

    
    void countWords(vector<string> &words, unordered_set<string> &banned,
                    unordered_map<string, int> &freq) 
    {
        for (string &w : words) {
            if (!banned.count(w)) freq[w]++;
        }
    }


public:

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());

        string cleaned = normalize(paragraph);

        vector<string> words;
        splitWords(cleaned, words);

        unordered_map<string, int> freq;
        countWords(words, bannedSet, freq);

        int maxFreq = 0;
        string mostWord = "";

        for (auto &it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                mostWord = it.first;
            }
        }

        return mostWord;
    }
};
