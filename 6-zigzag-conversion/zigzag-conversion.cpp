class Solution {
public:
    string convert(string s, int numRows) {
        
        // int len = s.length();
        // if(len == 1) return s;
        // string ans = "";
        // numRows--;
        // vector<int> vis(len , 0);
        // for(int i = 0 ; i <= numRows ; i++){
        //     if(numRows == 0) return s;
        //     cout << "i : " << i << endl;
        //     for(int j = 0 ; j < len ; j += (2 * (numRows))){
        //         if(i != 0 && j - i > 0 && vis[j - i] == 0) {ans += s[j - i]; vis[j - i] = 1;}
                
        //         cout << "j : " << j << " i : " << i << endl;
        //         cout << "i + j : " << i + j << "         j - i : " << j - i << endl << endl;
                
        //         if(j + i < len && vis[j + i] == 0) {ans += s[j + i]; vis[j + i] = 1; }
        //     }
        //     cout << "-----------------------------" << endl;
        // }

        // cout << ans << endl;
        // return ans;

        int len = s.length();
        if(numRows == 1) return s;
        vector<string> rows(min(len, numRows), "");
        int curr_row = 0;
        bool going_down = false;
        for(auto ch : s){
            rows[curr_row] += ch;

            if(curr_row == 0 || curr_row == numRows - 1) going_down = !going_down;

            curr_row += going_down ? 1 : -1;
        }

        string ans = "";
        for(auto it : rows){
            ans += it;
        }
        return ans;


    }
};