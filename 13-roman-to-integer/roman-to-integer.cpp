class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        int num = 0;
        int n = s.length();
        // for(int i = 0 ; i < n ; i++){
        //     if(s[i] == 'I' && s[i + 1] != 'I') {
        //         // num += 4;
        //         num += mpp[s[i + 1]] - 1;
        //         i++;
        //     }
        //     else if(s[i] == 'X' && s[i + 1] == 'C') {
        //         num += mpp[s[i + 1]] - 10;
        //         i++;
        //     }
        //     else if(s[i] == 'C' && s[i + 1] == 'M') {
        //         num += mpp[s[i + 1]] - 100;
        //         i++;
        //     }
        //     else num += mpp[s[i]];


        for (int i = 0; i < n; i++) {
            if (i < n - 1 && mpp[s[i]] < mpp[s[i + 1]]) {
                num += mpp[s[i + 1]] - mpp[s[i]];
                i++;
            } else {
                num += mpp[s[i]];
            }
        }


        return num;
    }
};