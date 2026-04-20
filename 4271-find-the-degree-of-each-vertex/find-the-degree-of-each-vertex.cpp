class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans;

        for(int col = 0 ; col < n ; col++){
            int degree = 0;
            for(int row = 0 ; row < n ; row++){
                degree += matrix[row][col];
            }
            ans.push_back(degree);
        }

        return ans;

    }
};