class Solution {

private:

    bool isValidWord(string & s, string & word, int idx){
        int end = word.size();
        for(int start = idx, word_idx = 0 ; word_idx < end ; start++, word_idx++){
            if(s[start] != word[word_idx]) return false;
        }
        return true;
    }

    void addIndexes(string & s, string & word, unordered_map<string, vector<int>> & mpp){
        int start = 0;
        int end = s.size();
        for(start = 0 ; start < end ; start++){
            if(s[start] == word[0] && isValidWord(s, word, start)) mpp[word].push_back(start);
        }
    }

    void getStartIndexs(string & s, vector<string> & words, unordered_map<string, vector<int>> & mpp){
        for(auto word : words){
            addIndexes(s, word, mpp);
        }
    }

    bool isPossibleSubString(string & s, int idx, unordered_map<string, int> & mpp, vector<int> & vis, int word_len){
        int len = s.size();

        if(idx >= len) return false;
        int pres_count = 1;
        int total_word_count = mpp.size();
        while(idx < len && total_word_count != pres_count++){
            string sub_str = "";
            int temp_idx = 0;
            while(idx < len && temp_idx++ < word_len){
                sub_str += s[idx++];
            }

            // cout << "Sub Str " << sub_str << endl;

            if(mpp.find(sub_str) == mpp.end()) {cout << "False " ; return false;}
            vis[mpp[sub_str]] = 1;
        }
        
        // for(int i : vis) cout << i << " ";
        // cout << endl;
        
        for(int i : vis) if (i == 0) return false;
        return true;
    }

    void getSubStrings(string & s, unordered_map<string, vector<int>> & word_index, vector<string> & words, vector<int> & indexes){
        unordered_map<string, int> word_idx;
        int w_idx = 0;
        for(auto it : words) word_idx[it] = w_idx++;


        // for(auto i : word_idx) cout << i.second << " ";
        // cout << endl;


        for(auto it : word_index){
            for(int idx : it.second){

                // cout << it.first << " " << idx << endl;
                
                vector<int> vis(words.size());
                vis[word_idx[it.first]] = 1;
                
                // for(int i : vis) cout << i << " ";
                // cout << endl;

                
                if(isPossibleSubString(s, idx + words[0].size() , word_idx, vis, it.first.length())) indexes.push_back(idx);
            }
        }
    }

public:

    // BRUTE FORCE METHOD
    // vector<int> findSubstring(string s, vector<string>& words) {
    //     unordered_map<string , vector<int>> word_start_idx;
        
    //     getStartIndexs(s, words, word_start_idx);

    //     // for(auto i : word_start_idx){
    //     //     for(int j : i.second) cout << j << " ";
    //     //     cout << endl;
    //     // }

    //     vector<int> indexes;

    //     getSubStrings(s, word_start_idx, words, indexes);

    //     return indexes;
    // }




    // METHOD USING SLIDIGN WINDOW 
    vector<int> findSubstring(string s, vector<string>& words){
        
        if(words.size() == 0) return {};
        vector<int> ans;
        
        int start_idx = 0;
        int total_words_count = words.size();
        int len = s.length();
        int word_len = words[0].size();
        unordered_map<string, int> word_count;
        for(auto word : words) word_count[word]++;
        
        for(int i = 0 ; i < word_len ; i++){
            start_idx = i;
            unordered_map<string, int> seen;
            int count = 0;
            for(int j = i ; j + word_len <= len ; j += word_len){
                string sub_str = s.substr(j, word_len);
                if(word_count.count(sub_str)){
                    seen[sub_str]++;
                    count++;

                    while(seen[sub_str] > word_count[sub_str]){
                        string sub_s = s.substr(start_idx, word_len);
                        seen[sub_s]--;
                        count--;
                        start_idx += word_len;
                    }

                    if(count == total_words_count) ans.push_back(start_idx);
                }else{
                    seen.clear();
                    count = 0;
                    start_idx = j + word_len;
                }
            }
        }

        return ans;
    
    
    }
};