class Solution {

private:

    // void solve(string s, string t, vector<string> &sub_str, string ans, int i){
    //     if (i == t.size()){
    //         sub_str.push_back(ans);
    //         return;
    //     }else{
    //         solve(s, t, sub_str, ans + t[i], i + 1);
    //         solve(s, t, sub_str, ans, i + 1);
    //     }
    // }


public:
    bool isSubsequence(string s, string t) {
        vector<string> sub_str;
        // solve(s, t, sub_str, "", 0);

        // for (string i : sub_str){
        //    if (i == s) return true;
        // }
        // return false;
        // bool answer = false;
        // int j = 0;
        // for(int i = 0 ; i < t.size() ; i++){
        //     if(t[i] == s[j]){
        //         j++;
        //     }
        // }

        // return j == s.size();
        // return answer;


        int len = t.length();
        int check_idx = 0;
        for(int idx = 0 ; idx < len ; idx++){
            if(s[check_idx] == t[idx]) check_idx++;
        }
        return check_idx == s.length();
    }
};