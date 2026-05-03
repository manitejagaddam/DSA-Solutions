class Solution {


private:
    bool compare(string s, string goal, int idx){
        int n = goal.length();
        int j = 0 ;
        for(int i = idx ; i < idx + n ; i++, j++){
            if(s[i] != goal[j]) return false;
        }
        return true;
    }

public:
    bool rotateString(string s, string goal) {
        if(goal.length() != s.length()) return false;
        s += s;
        // cout << s;

        int n = goal.length();
        for(int idx = 0 ; idx < n ; idx++){
            if(compare(s, goal, idx)) return true;
        }
        return false;
    }
};