class Solution {

private:
    void solve(vector<vector<char>> & grid, vector<vector<int>> & visited, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(int drow = -1 ; drow <= 1 ; drow++){
                for(int dcol = -1 ; dcol <= 1 ; dcol++){
                    if((drow == 0 && dcol == 1) ||  
                       (drow == 0 && dcol == -1) || 
                       (drow == 1 && dcol == 0) ||  
                       (drow == -1 && dcol == 0))   
                    {
                        int nrow = i + drow;
                        int ncol = j + dcol;
                        if(nrow >= 0 && nrow < m && 
                        ncol >= 0 && ncol < n &&
                        grid[nrow][ncol] == '1' &&
                        !visited[nrow][ncol]){
                            visited[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    solve(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};

// class Solution {
// private:
//     void solve(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col){
//         int n = grid.size();   // Rows
//         int m = grid[0].size(); // Columns
//         visited[row][col] = 1;

//         queue<pair<int, int>> q;
//         q.push({row, col});
        
//         while(!q.empty()){
//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();

//             // Possible moves (Up, Down, Left, Right, and Diagonals)
//             vector<pair<int, int>> directions = {
//                 {-1, 0}, {1, 0}, {0, -1}, {0, 1} // Up, Down, Left, Right
//                 // {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // Diagonals
//             };

//             for(auto dir : directions){
//                 int nrow = i + dir.first;
//                 int ncol = j + dir.second;

//                 if(nrow >= 0 && nrow < n && 
//                    ncol >= 0 && ncol < m &&
//                    grid[nrow][ncol] == '1' &&
//                    !visited[nrow][ncol]){
//                     visited[nrow][ncol] = 1;
//                     q.push({nrow, ncol});
//                 }
//             }
//         }
//     }

// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> visited(n, vector<int>(m, 0));
//         int count = 0;

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j] == '1' && !visited[i][j]){
//                     count++;
//                     solve(grid, visited, i, j);
//                 }
//             }
//         }
//         return count;
//     }
// };
