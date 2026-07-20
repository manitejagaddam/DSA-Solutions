class Solution {

private:
    void reverse(vector<vector<int>> & grid){
        // int m {static_cast<int>(grid.size())};
        // int n {static_cast<int>(grid[0].size())};
        int m = grid.size();
        int n = grid[0].size();
        int last_ele {grid[m - 1][n - 1]};


        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) continue;
                if (j == 0 && i > 0) {
                    grid[i][j] = grid[i-1][n-1];
                } 
                else {
                    grid[i][j] = grid[i][j-1];
                }
            }
        }
        
        grid[0][0] = last_ele;
    }

public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // int n {static_cast<int>(grid.size())};
        // k %= n;
        // reverse(grid.begin() + n - k, grid.end());
        // reverse(grid.begin(), grid.begin() + n - k);
        // reverse(grid.begin(), grid.end());
        // return grid;

        // for(int idx = 0 ; idx < k ; idx++) reverse(grid);
        // return grid;

        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int oldIndex = i * n + j;

                int newIndex = (oldIndex + k) % total;

                int newRow = newIndex / n;
                int newCol = newIndex % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;

    }
};