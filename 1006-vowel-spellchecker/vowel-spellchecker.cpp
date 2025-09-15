// class Solution {

// private:
    
//     string toLower(string word){
//         string ans = "";
//         for(char ch : word){
//             ans += tolower(ch);
//         }
//         return ans;
//     }

//     bool isVowel(char ch){
//         char c = tolower(ch);
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//     }

// public:
//     vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
//         unordered_set<string> st(wordlist.begin(), wordlist.end());
//         unordered_set<string> lower_words;
//         for(string word : wordlist) lower_words.insert(toLower(word));
//         vector<string> ans;
//         string vowels = "aeiou";
//         auto vowelMatch = [&lower_words, &st, &ans, this, &vowels] (string word){
//             int len = word.length();
//             for(int idx = 0 ; idx < len ; idx++){
//                 if(isVowel(word[idx])){
//                     char org = word[idx];
//                     for(char ch : vowels){
//                         word[idx] = ch;
//                         if(st.find(word) != st.end()) {
//                             ans.push_back(word);
//                             return true;    
//                         }
//                         else if(lower_words.find(toLower(word)) != lower_words.end()) {
//                             ans.push_back(toLower(word)); 
//                             return true;    
//                         }
//                     }
//                 }
//             }
//             return false;

//         };


//         for(string query : queries){
//             if(st.find(query) != st.end()) ans.push_back(query);
//             else if(lower_words.find(toLower(query)) != lower_words.end() ) ans.push_back(toLower(query));
//             else if(vowelMatch(query)) continue;
//             else ans.push_back("");
//         }

//         return ans;
//     }
// };



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Convert word to lowercase
    string toLower(const string &word) {
        string ans = "";
        for (char ch : word) {
            ans += tolower(ch);
        }
        return ans;
    }

    // Check if character is a vowel
    bool isVowel(char ch) {
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    // Replace all vowels with '*'
    string replaceVowels(const string &word) {
        string res = "";
        for (char ch : word) {
            res += (isVowel(ch) ? '*' : tolower(ch));
        }
        return res;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact_words(wordlist.begin(), wordlist.end());

        // Maps for case-insensitive and vowel-insensitive matches
        unordered_map<string, string> case_insensitive;
        unordered_map<string, string> vowel_insensitive;

        for (const string &word : wordlist) {
            string lower = toLower(word);
            string vowel_replaced = replaceVowels(lower);

            // Only insert the first occurrence to maintain priority
            if (!case_insensitive.count(lower))
                case_insensitive[lower] = word;

            if (!vowel_insensitive.count(vowel_replaced))
                vowel_insensitive[vowel_replaced] = word;
        }

        vector<string> ans;

        for (string query : queries) {
            if (exact_words.count(query)) {
                // Exact match
                ans.push_back(query);
            } 
            else {
                string lower_query = toLower(query);
                string vowel_query = replaceVowels(lower_query);

                if (case_insensitive.count(lower_query)) {
                    ans.push_back(case_insensitive[lower_query]);
                } 
                else if (vowel_insensitive.count(vowel_query)) {
                    ans.push_back(vowel_insensitive[vowel_query]);
                } 
                else {
                    ans.push_back("");
                }
            }
        }

        return ans;
    }
};
