class Solution {

private:
    // void solve(int n, vector<string> &result, string ans, int openCount, int closeCount){
    //     if(openCount == n && closeCount == n) result.push_back(ans);
    //     else{
    //         if(openCount < n) {
    //             solve(n, result, ans + '(', openCount + 1, closeCount);
    //         }
    //         if(closeCount < openCount){
    //             solve(n, result, ans + ')', openCount, closeCount + 1);
    //         }
    //     }
    // }


    void solve(int n, vector<string> & result, string ans, int opencount, int closecount){
        if(opencount == n && closecount == n){
            result.push_back(ans);
        }
        else{
            if(opencount < n){
                solve(n, result, ans + '(', opencount + 1, closecount);
            }
            if(closecount < opencount){
                solve(n, result, ans + ')', opencount, closecount + 1);
            }
        }
    }


 

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, result, "", 0, 0);
        return result;
    }
};