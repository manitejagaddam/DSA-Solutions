class Solution {
public:
    int calculate(string s) {

        int res = 0;
        int curr = 0;
        int sign = 1;
        stack<int> st;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){

            if(s[i] >= '0' && s[i] <= '9'){
                curr = curr * 10 + (s[i] - '0');
                while(i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '9'){
                    curr = curr * 10 + (s[i + 1]- '0');
                    i++;
                }

                curr *= sign;
                res += curr;
                curr = 0;
            }
            else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
            }else if(s[i] == ')'){
                int prev_sign = st.top();
                st.pop();
                res *= prev_sign;
                int prev_res = st.top();
                st.pop();
                res += prev_res;
            }else{
                continue;
            }   

        }
        
        return res;
    }

};