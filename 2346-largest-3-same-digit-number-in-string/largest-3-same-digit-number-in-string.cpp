class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int len = num.length();
        for(int idx = 0 ; idx < len - 2 ; idx++){
            if(num[idx] == num[idx + 1] && num[idx] == num[idx + 2]){
                if(ans.length() == 0) ans = num.substr(idx, 3);
                else if(ans[0] < num[idx]) ans = num.substr(idx, 3);
            }
        }
        return ans;
    }
};