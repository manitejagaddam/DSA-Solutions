class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int noe = temperatures.size();
        vector<int> ans(noe, 0);
        for(int idx = 0 ; idx < noe ; idx++){
            int count = 1;
            while(!st.empty() && temperatures[st.top()] < temperatures[idx]){
                ans[st.top()] = idx - st.top();
                st.pop();
            }
            st.push(idx);
        }
        return ans;
    }
};