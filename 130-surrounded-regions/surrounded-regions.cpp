class Solution {

private:
    void dfs(int row, int col, vector<vector<char>> & board, vector<vector<int>> & vis, vector<pair<int, int>> & dir){
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        for(auto i : dir){
            int nr = row + i.first;
            int nc = col + i.second;

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'O' && !vis[nr][nc]){
                dfs(nr, nc, board, vis, dir);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if(board[i][j] == 'O' && !vis[i][j]){
                        dfs(i,j,board,vis,dir);
                    }
                }
            }
        }

        for(int i = 1 ; i < m - 1 ; i++){
            for(int j = 1 ; j < n - 1 ; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }

    }
};