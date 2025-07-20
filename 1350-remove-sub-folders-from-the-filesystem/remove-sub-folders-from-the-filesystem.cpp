class Solution {

private:
    bool isSubFolder(string & s1, string & s2){
        int len = s1.length();
        int idx;
        for(idx = 0 ; idx < len ; idx++){
            if(s1[idx] != s2[idx]) return false;
        }
        
        return s2.length() > len && s2[len] == '/';
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        int len = folder.size();
        for(int idx = 0 ; idx < len ; idx++){
            if(ans.size() == 0 || !isSubFolder(ans.back(), folder[idx])) ans.push_back(folder[idx]);
        }
        return ans;
    }
};