class Solution {
public:
    int maxOperations(string s) {
        // int len = s.length();
        // int lastOneIdx = len - 1;
        // int operations = 0;
        // if(s[lastOneIdx] == '1')
        //     while(lastOneIdx >= 0 && s[lastOneIdx] == 1) lastOneIdx--;
        // else{
        //     int temp = lastOneIdx;
        //     while(temp >= 0 && s[temp] != 1){
        //         temp--;
        //     }
        //     operations += lastOneIdx - temp;
        // }
        // cout << operations << endl;
        // for(int idx = len - 2 ; idx >= 0 ; idx--){
        //     if(s[idx] == '1' ){
        //         // cout << "1 found" << endl;
        //         operations += lastOneIdx - idx - 1;
        //         lastOneIdx--;
        //         cout << lastOneIdx << " " << idx << " " << operations << endl;
        //     }
        // }
        // return operations;

        int countOne = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                while ((i + 1) < s.length() && s[i + 1] == '0') {
                    i++;
                }
                ans += countOne;
            } else {
                countOne++;
            }
        }
        return ans;
    }
};