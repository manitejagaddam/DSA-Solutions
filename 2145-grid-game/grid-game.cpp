class Solution {

private:
    int row_len = 2, col_len, ans;
    void backtrack(vector<vector<int>> & grid, int row, int col, int firstSum, int secondSum){
        if(row == row_len || col == col_len){
            ans = min(ans, secondSum);
            return;
        }

        backtrack(grid, row, col + 1, firstSum + grid[row][col], secondSum - grid[row][col]);
        backtrack(grid, row + 1, col, firstSum + grid[row][col], secondSum - grid[row][col]);
    }

public:
    long long gridGame(vector<vector<int>>& grid) {
        // col_len = grid[0].size();
        // int sum = 0;
        // ans = INT_MAX;
        // for(auto row : grid){
        //     for(int ele : row){
        //         sum += ele;
        //     }
        // }       

        // backtrack(grid, 0, 0, 0, sum);
        // return ans;

        long long firstRowSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long secondRowSum = 0;
        int len = grid[0].size();

        long long mini = LONG_LONG_MAX;
        for(int idx = 0 ; idx < len ; idx++){
            firstRowSum -= grid[0][idx];

            mini = min(mini, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][idx];
        }
        return mini;
    }
};