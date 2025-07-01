class Solution {

private:

    bool charIn(char & ch, string & s){
        int len = s.length();
        for(char c : s) 
            if(ch == c) 
                return true;
        
        return false;
    }

    bool matchStr(string & s1, string & s2){
        int len = s1.length();
        for(int i = 1 ; i < len ; i++){
            if(!charIn(s1[i], s2)) return false;
        }
        return true;
    }

    bool possible(string & word){
        string r1 = "qwertyuiopQWERTYUIOP";
        string r2 = "asdfghjklASDFGHJKL";
        string r3 = "zxcvbnmZXCVBNM";

        int len1 = r1.length();
        int len2 = r2.length();
        int len3 = r3.length();

        // check fro r1
        for(int i = 0 ; i < len1 ; i++){
            if(word[0] == r1[i]){
                return matchStr(word, r1);
            }
        }
        
        // check for r2
        for(int i = 0 ; i < len2 ; i++){
            if(word[0] == r2[i]){
                return matchStr(word, r2);
            }
        }

        // check for r3
        for(int i = 0 ; i < len3 ; i++){
            if(word[0] == r3[i]){
                return matchStr(word, r3);
            }
        }

        return false;

    }

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(string word : words){
            if(possible(word)) ans.push_back(word);
        }
        return ans;
    }
};