class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 1) return strs[0]; 

        sort(strs.begin(), strs.end());

        int n = strs[0].size();
        int m = strs.size();

        int count = 0;

        if(strs[0] == "") return "";

        string ans = "";

        for(int i = 0 ; i < n ; i++){
            char s = strs[0][i];
            bool same = true;
            for(int j = 0 ; j < m ; j++){
                if(strs[j][i] != s){
                    same = false;
                    break;
                }
            }
            // if(same) ans += strs[0][i];
            if(same) count++;
            if(!same) break;
        }

        // return ans;
        return strs[0].substr(0, count);
        

        // if (strs.size() == 1) return strs[0];

        // sort(strs.begin(), strs.end());
        // int count = 0;
        // int n = strs[0].size();

        // for(int i = 0 ; i < n ; i++){
        //     if(strs[0][i] != strs[1][i]) break;
        //     count++;
        // }
        // return strs[0].substr(0, count);
        

        
    }
};