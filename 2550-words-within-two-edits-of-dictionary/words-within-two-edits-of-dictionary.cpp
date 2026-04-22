class Solution {

private:

    bool canEdit(string word1, string word2){

        int len = word1.length();
        int idx = 0;
        int count = 2;
        // cout << word1 << " " << word2 << endl;
        for(int idx = 0 ; idx < len ; idx++){
            if(word1[idx] != word2[idx]) count--;
            if(count == -1) return false;
        }

        return true;
    }

    bool isPossible(string word, vector<string> & dic){

        for(string comp : dic){
            if(canEdit(word, comp)) return true;
        }

        return false;
    }

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string word : queries){
            if(isPossible(word, dictionary)) ans.push_back(word);
        }
        return ans;
    }
};