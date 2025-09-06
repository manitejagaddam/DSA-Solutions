class Solution {

private:
    vector<int> PSE(vector<int> & nums){
        int noe = nums.size();
        vector<int> ans(noe, -1);
        stack<int> st;
        for(int idx = 0 ; idx < noe ; idx++){
            while(!st.empty() && nums[st.top()] >= nums[idx]) st.pop();
            // if(!st.empty()) ans[idx] = nums[st.top()];
            if(!st.empty()) ans[idx] = st.top();
            st.push(idx);
        }
        return ans;
        
    }

    vector<int> NSE(vector<int> & nums){
        int noe = nums.size();
        vector<int> ans(noe, noe);
        stack<int> st;
        for(int idx = noe - 1 ; idx >= 0 ; idx--){
            while(!st.empty() && nums[st.top()] >= nums[idx]){
                // ans[st.top()] = nums[idx];
                // ans[st.top()] = idx;
                st.pop();
            }
            if(!st.empty()) ans[idx] = st.top();
            st.push(idx);
        }
        // for(int idx = noe - 1 ; idx >= 0 ; idx--){
        //     while(!st.empty() && nums[st.top()] >= nums[idx]){
        //         // ans[st.top()] = nums[idx];
        //         // ans[st.top()] = idx;
        //         st.pop();
        //     }
        //     if(!st.empty()) ans[idx] = st.top();
        //     st.push(idx);
        // }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        int noe = heights.size();

        int maxArea = 0;
        for(int rectangle = 0 ; rectangle < noe ; rectangle++){
            int width = nse[rectangle] - pse[rectangle] - 1; 
            maxArea = max(maxArea, heights[rectangle] * width);
        }
        return maxArea;
    }
};