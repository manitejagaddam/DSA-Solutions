class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int len = s.length();
        for(int i = 0 ; i < len ; i++){
            if(i > 0 && i < len - 1){
                if(s[i - 1] == s[i] && s[i] == s[i + 1]) continue;
            }
            ans += s[i];
        }
        return ans;
    }
};