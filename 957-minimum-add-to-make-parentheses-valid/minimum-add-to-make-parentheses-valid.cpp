class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for(char i : s) {
            if(i == '(') open++;
            else if(i == ')' && open > 0) open--;
            else close++;
        }
        return abs(open + close);
    }
};