class Solution {
public:
    bool judgeCircle(string moves) {
        int dirUp = 0, dirSide = 0;
        for(char ch : moves){
            if(ch == 'U') dirUp++;
            else if(ch == 'D') dirUp--;
            else if(ch == 'L') dirSide++;
            else dirSide--;
        }
        return !dirUp && !dirSide;
    }
};