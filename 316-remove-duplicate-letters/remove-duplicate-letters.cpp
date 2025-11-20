class Solution {

private:

    bool isPossible(string & temp, string & s){
        vector<char> mpp(26);
        for(char ch : s) mpp[ch - 'a'] = 1;
        for(char ch : temp) {
            mpp[ch - 'a'] -= 1;
        }
        for(int i : mpp) if(i) return false;
        return true;
    }

    void backtrack(string & s, int idx, string temp, string & ans){
        if(idx > s.length()) return;
        cout << temp << endl;
        if(isPossible(temp, s) && ans > temp) ans = temp;

        backtrack(s, idx + 1, temp, ans);
        backtrack(s, idx + 1, temp + s[idx], ans);
        // temp.pop_back();
    }

public:
    string removeDuplicateLetters(string s) {
        // vector<int> mpp(26, -1);
        // for(char ch : s) mpp[ch - 'a']++;
        // string ans = "";
        // for(int i : mpp) cout << i << " ";
        // cout << endl;
        // for(int i = 0 ; i < 26 ; i++){
        //     if(mpp[i] != -1){
        //         char ch = 'a' + i;
        //         ans += ch;
        //     }
        // }
        // return ans;

        // string ans = "zzzzzz";
        // string temp = "";

        // backtrack(s, 0, temp, ans);

        // return ans;

        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        for(char c : s) 
            freq[c - 'a']++;

        stack<char> st;

        for(char c : s) {
            freq[c - 'a']--;

            if(used[c - 'a'])
                continue;

            while(!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                used[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            used[c - 'a'] = true;
        }

        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;

    }
};