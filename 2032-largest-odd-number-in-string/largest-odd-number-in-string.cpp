class Solution {
public:
    string largestOddNumber(string num) {
        int idx = num.size() - 1;
        // while((num[idx] - '0') % 2 == 1) idx--;
        for(; idx >= 0 ; idx--){
            cout << num[idx] - '0' << " ";
            if((num[idx] - '0') % 2 == 1) break;
            cout << num[idx] - '0' << " ";
            
        }
        return num.substr(0, idx + 1);
    }
};