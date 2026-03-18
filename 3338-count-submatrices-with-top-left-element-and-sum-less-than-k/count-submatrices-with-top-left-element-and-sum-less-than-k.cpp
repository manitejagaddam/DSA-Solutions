class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        int count = 0;
        
        // creating the row wise prefix Sum
        for(int row = 0 ; row < rowLen ; row++){
            for(int col = 1 ; col < colLen ; col++){
                grid[row][col] += grid[row][col - 1];
            }
        }

        // creating the Entire PrefixSum Map

        for(int col = 0 ; col < colLen ; col++){
            for(int row = 1 ; row < rowLen ; row++){
                grid[row][col] += grid[row - 1][col];
            }
        }

        for(auto row : grid){
            for(int ele : row){
                if(ele <= k) count++;
            }
        }

        // for(auto it : grid){
        //     for(int ele : it){
        //         cout << ele << " ";
        //     }cout << endl;
        // }

        return count;
    }
};