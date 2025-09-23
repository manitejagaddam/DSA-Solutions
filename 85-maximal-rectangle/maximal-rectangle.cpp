class Solution {


private:

    vector<int> previousSmallestElement(vector<int> & nums){
        int len = nums.size();
        vector<int> ans(len, -1);
        stack<int> st;
        for(int idx = len - 1 ; idx >= 0 ; idx--){
            while(!st.empty() && nums[st.top()] > nums[idx]){
                ans[st.top()] = idx;
                st.pop();
            }
            st.push(idx);
        }
        return ans;
    }

    vector<int> nextSmallestElement(vector<int> & nums){
        int len = nums.size();
        vector<int> ans(len, len);
        stack<int> st;
        for(int idx = 0 ; idx < len ; idx++){
            while(!st.empty() && nums[st.top()] > nums[idx]){
                ans[st.top()] = idx;
                st.pop();
            }
            st.push(idx);
        }
        return ans;
    }

    int maximumRectangle(vector<int> & nums){
        vector<int> left = previousSmallestElement(nums);
        vector<int> right = nextSmallestElement(nums);
        int ans = INT_MIN;

        int len = nums.size();
        for(int idx = 0 ; idx < len ; idx++){
            int width = right[idx] - left[idx] - 1;
            ans = ans < nums[idx] * width ? nums[idx] * width : ans; 
        }
        return ans;
    }




public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for(int col = 0 ; col < n ; col++) mat[0][col] = matrix[0][col] - '0';
        for(int row = 1 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                mat[row][col] = (matrix[row][col] == '1') ? mat[row - 1][col] + 1 : 0;
            }
        }
        for(int row = 0 ; row < m ; row++){
            int tempArea = maximumRectangle(mat[row]);
            ans = ans < tempArea ? tempArea : ans;
        }

        return ans;
    }
};