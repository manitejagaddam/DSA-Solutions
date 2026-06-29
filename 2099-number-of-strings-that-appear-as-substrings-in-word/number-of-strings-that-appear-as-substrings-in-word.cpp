class Solution {

private:

    bool compareStr(string str1, string str2, int idx){
        int n = str2.length();
        int idx2 = 0;
        while(idx2 < str1.length() && idx < n){
            if(str1[idx2++] != str2[idx++]) return false;
        }
        return true;
    }

    bool isSubstring(string & str1, string & str2){
        if(str1.length() > str2.length()) return false;
        bool found = false;
        for(int idx = 0 ; idx <= str2.length() - str1.length() ; idx++){
            // if(str2[idx] == str1[idx2]){
            //     idx2++;
            //     if(idx2 == str1.length()) return true;
            // }else idx2 = 0;
            if(str2[idx] == str1[0]){
                if(compareStr(str1, str2, idx)) return true;
            }
        }
        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string s : patterns){
            count += isSubstring(s, word);
        }
        return count;
    }
};