class Solution {

private:
    string join(vector<string>& words, const string& delimiter) {
        if (words.empty()) return "";
        string result = words[0];
        for (int i = 1; i < words.size(); i++) {
            result += delimiter + words[i];
        }
        return result;
    }

public:
    string reverseWords(string s) {
        // int n = s.size();
        // string ans = "";
        // int count = 0;
        // for(int i = 0 ; i < n ; i++){
        //     if(s[i] == ' ') continue;
        //     string word = "";
        //     while(i < n && s[i] != ' '){
        //         word += s[i];
        //         i++;
        //         cout << count << " ";
        //     }
        //     ans = word + " " + ans;
        //     cout << ans << " ";
        //     count++;
        // }
        // ans.pop_back();

        // return ans;


    //     vector<string> words;
    //     int n = s.size();
    //     for (int i = 0; i < n; i++) {
    //         if (s[i] == ' ') continue;
    //         string word = "";
    //         while (i < n && s[i] != ' ') {
    //             word += s[i];
    //             i++;
    //         }
    //         words.push_back(word);
    //     }
    //     reverse(words.begin(), words.end()); 
    //     return join(words, " ");  



        vector<string> words;
        int len = s.length();
        for(int idx = 0 ; idx < len ; idx++){
            if(s[idx] == ' ') continue;
            string word = "";
            while(idx < len && s[idx] != ' '){
                word += s[idx++];
            }
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        return join(words, " ");

    }
};