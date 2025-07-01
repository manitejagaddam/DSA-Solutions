class Solution {
public:
    string finalString(string s) {
        string ans = "";
        // for(char ch : s){
        //     if (ch == 'i') reverse(ans.begin(), ans.end());
        //     else ans += ch;
        // }

        int len = s.length();
        for(int i = 0 ; i < len ; i++){
            if(s[i] == 'i') reverse(ans.begin(), ans.end());
            else ans += s[i];
        }
        return ans;
    }
};