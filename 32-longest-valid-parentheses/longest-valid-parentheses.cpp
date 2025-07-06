class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxLen = 0;
        int len = s.length();
        st.push(-1);


        for(int i = 0 ; i < len ; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    // maxLen = max(maxLen, i - st.top());
                    maxLen = maxLen < i - st.top() ? i - st.top() : maxLen;
                }

            }
        }

        return maxLen;
    }
};