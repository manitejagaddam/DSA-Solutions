class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int len = s.length();
        for(int digit = 0 ; digit < len ; digit++){
            if(s[digit] == '6'){
                s[digit] = '9';
                return stoi(s);
            }
        }
        return num;
    }
};