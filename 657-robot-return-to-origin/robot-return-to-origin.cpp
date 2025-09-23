class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizontal = 0;
        for(char ch : moves){
            switch(ch){
                case 'U' : {
                    vertical++;
                    break;
                }
                case 'D' : {
                    vertical--;
                    break;
                }
                case 'L' : {
                    horizontal--;
                    break;
                }
                case 'R' : {
                    horizontal++;
                    break;
                }
            }
        }

        return horizontal == 0 && vertical == 0;
    }
};