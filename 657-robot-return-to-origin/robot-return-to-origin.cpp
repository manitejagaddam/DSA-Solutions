class Solution {
public:
    bool judgeCircle(string moves) {
        int dirX = 0, dirY = 0;
        for(char ch : moves){
            if(ch == 'U') dirX++;
            else if(ch == 'D') dirX--;
            else if(ch == 'L') dirY++;
            else dirY--;
        }
        return !dirX && !dirY;
    }
};