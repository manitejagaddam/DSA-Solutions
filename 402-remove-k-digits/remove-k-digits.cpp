class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length()) return "0";
        stack<char> s;
        for(char i : num){
            while (k > 0 && !s.empty() && s.top() > i){
                s.pop();
                k--;
            }
            s.push(i);
        }

        while(k){
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.length() && ans[i] == '0') i++;
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;

    }
};