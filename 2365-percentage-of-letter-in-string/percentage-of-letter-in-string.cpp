class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for(char ch : s){
            if(ch == letter) count++;
        }
        cout << count << " " << s.length() << " " << count / s.length();
        return (count * 100) / s.length();
    }
};