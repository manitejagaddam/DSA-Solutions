class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;
        while(row < m && col >= 0){
            cout << matrix[row][col];
            if(matrix[row][col] == target) return true;
            else if(matrix[row][n - 1] < target){
                row++;
            }else{
                while(col >= 0){
                    if(matrix[row][col--] == target) return true;
                }
                return false;
            }
        }
        return false;
    }
};