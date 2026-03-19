class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        vector<vector<pair<int, int>>> mat(rowLen, vector<pair<int, int>>(colLen, {0, 0}));

        grid[0][0] == 'X' ? mat[0][0].first++ : (grid[0][0] == 'Y' ? mat[0][0].second++ : 0);

        for(int col =  1 ; col < colLen ; col++){
            mat[0][col].first = mat[0][col - 1].first;
            mat[0][col].second = mat[0][col - 1].second;
            grid[0][col] == 'X' ? (mat[0][col].first++) : 
                                  (grid[0][col] == 'Y' ? mat[0][col].second++ : 0);
        }
        
        // for(int row = 0 ; row < rowLen ; row++){
        //     for(int col = 0 ; col < colLen ; col++){
        //         cout << "{ " << mat[row][col].first << ", " << mat[row][col].second << " }   "; 
        //     }cout << endl;
        // }

        for(int row = 1 ; row < rowLen ; row++){
            for(int col = 0 ; col < colLen ; col++){
                mat[row][col].first = mat[row - 1][col].first;
                mat[row][col].second = mat[row - 1][col].second;

                if(col > 0) {
                    mat[row][col].first += mat[row][col - 1].first;
                    mat[row][col].second += mat[row][col - 1].second;
                }

                if(col > 0){
                    mat[row] [col].first -= mat[row - 1] [col - 1].first;
                    mat[row] [col].second -= mat[row - 1] [col - 1].second;
                }
                 
                grid[row] [col] == 'X' ? (mat[row] [col].first += 1) : 
                          (grid[row] [col] == 'Y' ? mat[row] [col].second += 1 : 0); 
            }
        }

        // for(int row = 0 ; row < rowLen ; row++){
        //     for(int col = 0 ; col < colLen ; col++){
        //         cout << "{ " << mat[row][col].first << ", " << mat[row][col].second << " }   "; 
        //     }cout << endl;
        // }

        int count = 0;
        // if(grid[0][0] != '.'){
        //     for(int col = 0 ; col < colLen ; col++) {
        //         count += (mat[0][col].first == mat[0][col].second && mat[0][col].first != 0) ? 1 : 0;
        //     }
        // } 
        for(int row = 0 ; row < rowLen ; row++){
            for(int col = 0 ; col < colLen ; col++){
                count += (mat[row] [col].first == mat[row] [col].second && mat[row] [col].first != 0) ? 1 : 0;
            }
        }
        return count;
    }
};