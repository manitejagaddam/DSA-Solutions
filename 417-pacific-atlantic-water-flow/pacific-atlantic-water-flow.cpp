class Solution {

private:    
    vector<vector<int>> mark;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int row_len = 0, col_len = 0;

    void dfs(vector<vector<int>> & heights, int row, int col, vector<vector<int>> & vis){
        mark[row][col]++;
        vis[row][col] = 1;
        
        for(auto [dx, dy] : dir){
            int nr = row + dx;
            int nc = col + dy;
            if(nr >= 0 && nr < row_len && nc >= 0 && nc < col_len 
               && !vis[nr][nc] && heights[row][col] <= heights[nr][nc]) {
                dfs(heights, nr, nc, vis);
            }
        }
    }



public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        row_len = m;
        col_len = n;

        vector<vector<int>> vis(m, vector<int>(n, 0));
        mark.resize(m, vector<int>(n, 0));

        // for pacific ocean marking
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(row == 0 || col == 0){
                    if(!vis[row][col]) dfs(heights, row, col, vis);
                }
            }    
        }

        // clear all the visiting marks in the vis vector
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                vis[row][col] = 0;
            }
        }

        // for atantic ocean
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(row == m - 1 || col == n - 1){
                    if(!vis[row][col]) dfs(heights, row, col, vis);
                }
            }
        }

        vector<vector<int>> ans;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(mark[row][col] == 2) ans.push_back({row, col});
            }
        }

        return ans;


    }
};