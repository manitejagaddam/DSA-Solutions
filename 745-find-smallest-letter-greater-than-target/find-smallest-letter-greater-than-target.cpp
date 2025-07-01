class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mini = INT_MAX;
        char ans;
        for(char i : letters){
            if(i < mini && i > target){
                mini = i;
                ans = i;
            }
        }
        
        return mini == INT_MAX ? letters[0] : ans;
        
    }
};