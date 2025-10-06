class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()){
            auto [level, row, col] = pq.top();
            pq.pop();
            
            if(vis[row][col]) continue;

            vis[row][col] = 1;


            if(row == m - 1 && col == n - 1) return level;
            // if(row == m - 1 && col == n - 1) mini = mini > level ? level : mini;

            for(auto [dx, dy] : dir){
                int nr = row + dx;
                int nc = col + dy;

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc]){
                    // int new_time = max(time, grid[nr][nc]);
                    int new_time = level < grid[nr][nc] ? grid[nr][nc] : level;
                    pq.push({new_time, nr, nc});
                }
            }
        }

        return -1;
    }
};