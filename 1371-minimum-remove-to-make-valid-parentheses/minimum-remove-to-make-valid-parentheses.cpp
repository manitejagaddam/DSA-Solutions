class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack<char> st;
        // string ans = "";
        // for(char ch : s){
        //     if(ch == '(') {
        //         st.push('(');
        //         ans += ch;
        //     } 
        //     else if(ch == ')') {
        //         if(st.empty()) continue;
        //         ans += ch;
        //         st.pop();
        //     }else{
        //         ans += ch;
        //     }
        // }
        // // while(!st.empty()){
        // //     ans += st.top();
        // //     st.pop();
        // // }
        // // bool foundChar = false;
        // // for(char it : ans) {
        // //     if(it != '(') {
        // //         foundChar = true;
        // //         break;
        // //     }
        // // }
        // int end = ans.length() - 1;
        // while(end >= 0 && ans[end] != ')' && ans[end] == '(') ans[end--] = '';
        // if(!foundChar) return "";
        // return ans;


        stack<int> stk;
        unordered_set<int> removalIndexes;
        int len = s.length();
        for(int idx = 0 ; idx < len ; idx++){
            if(s[idx] == '('){
                stk.push(idx);
            }else if(s[idx] == ')'){
                if(!stk.empty()) stk.pop();
                else removalIndexes.insert(idx);
            }
        }

        while(!stk.empty()){
            removalIndexes.insert(stk.top());
            stk.pop();
        }

        string ans = "";
        for(int idx = 0 ; idx < len ; idx++){
            if(removalIndexes.find(idx) != removalIndexes.end()) continue;
            ans += s[idx];
        }

        return ans;


    }
};