class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> oneRow, oneCol, zeroRow, zeroCol;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++){
            int ones = 0;
            for(int j = 0 ; j < n ; j++){
                ones += grid[i][j];
            }
            oneRow.push_back(ones);
            zeroRow.push_back(n - ones);
        }

        for(int i = 0 ; i < n ; i++){
            int ones = 0;
            for(int j = 0 ; j < m ; j++){
                ones += grid[j][i];
            }
            oneCol.push_back(ones);
            zeroCol.push_back(m - ones);
        }

        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                ans[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }

        return ans;
    }
};