// class Solution {

// private:
//     int solve(int i, int j, int m, int n, vector<vector<int>> &grid, int limit, int current){
//         if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -2 || grid[i][j] == -1){
//             return 0;
//         }
        
//         if (grid[i][j] == 2) {
//             if (current == limit) { 
//                 return 1;
//             }
//             return 0;
//         }

//         else{
//             int temp = grid[i][j];
//             grid[i][j] = -2;
//             int up = solve(i - 1, j, m, n, grid, limit, current + 1);
//             int back = solve(i, j - 1, m, n, grid, limit, current + 1); 
//             int down = solve(i + 1, j, m, n, grid, limit, current + 1); 
//             int front = solve(i, j + 1, m, n, grid, limit, current + 1); 
//             grid[i][j] = temp;
//             return up + back + down + front;
//         }
//     }

// public:
//     int uniquePathsIII(vector<vector<int>>& grid) {
  
//         int m = grid.size();
//         int n = grid[0].size();
//         int wakable = 0;
//         int start1 = 0;
//         int start2 = 0;

//         // Locate the start position and count walkable cells
//         for(int i = 0 ; i < m ; i++){
//             for(int j = 0 ; j < n ; j++){
//                 if (grid[i][j] == 1) {
//                     start1 = i;
//                     start2 = j;
//                 }
//                 if(grid[i][j] != -1){
//                     wakable++;
//                 }
//             }
//         }
//         int limit = wakable - 1;

//         grid[start1][start2] = -2;
//         return solve(start1, start2, m, n, grid, limit, 1); 
//     }
// };

class Solution {
private:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, int limit, int current) {

        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1 || grid[i][j] == -2) {
            return 0;
        }

        if (grid[i][j] == 2) {
            if (current == limit) {
                return 1;
            }
            return 0;
        }

        int temp = grid[i][j];
        grid[i][j] = -2;

        int paths = 0;
        paths += solve(i - 1, j, m, n, grid, limit, current + 1); 
        paths += solve(i + 1, j, m, n, grid, limit, current + 1); 
        paths += solve(i, j - 1, m, n, grid, limit, current + 1); 
        paths += solve(i, j + 1, m, n, grid, limit, current + 1); 

        grid[i][j] = temp;

        return paths;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int wakable = 0;
        int start1 = 0, start2 = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start1 = i;
                    start2 = j;
                }
                if (grid[i][j] != -1) {
                    wakable++;
                }
            }
        }

        int limit = wakable;

        return solve(start1, start2, m, n, grid, limit, 1);
    }
};
