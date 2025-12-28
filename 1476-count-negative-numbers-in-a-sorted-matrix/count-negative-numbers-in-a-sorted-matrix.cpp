class Solution {

private:
    int findBp(vector<vector<int>> & grid, int row){
        int len = grid[row].size();
        int start = 0;
        int end = len - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(grid[row][mid] < 0) {
                end = mid;
                end = mid - 1;
            }else start = mid + 1;
        }
        return start;
    }

public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int row = 0 ; row < m ; row++){
            count += n - findBp(grid, row);
        }
        return count;
    }
};