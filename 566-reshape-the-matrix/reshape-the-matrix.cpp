class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int row = 0;
        int col = 0;
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) return mat;
        for(int old_row = 0 ; old_row < m ; old_row++){
            for(int old_col = 0 ; old_col < n ; old_col++){
                ans[row][col] = mat[old_row][old_col]; 
                col++;
                if (col == c) { 
                    col = 0;
                    row++;
                }
            }
        }   


        return ans;
    }
};