class Solution {
public:
    int maxPower(string s) {
        int maxi = 0;
        int count = 0;
        int len = s.length();
        for(int idx = 1 ; idx < len ; idx++){
            if(s[idx - 1] == s[idx]){
                count++;
                maxi = max(maxi, count);
            }else count = 0;
        }
        return maxi + 1;
    }
};