class Solution {

private:
    unordered_map<int, vector<pair<int, int>>> indexes_map;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}};
    int ans = INT_MAX;
    int row_len, col_len;
    vector<vector<vector<int>>> dp;

    int backtrack(vector<vector<int>> & grid, int row, int col, int cost, int k){
        if(row == row_len - 1 && col == col_len - 1) {
            ans = ans > cost ? cost : ans;
            return 0;
        }
        if(row == row_len || col == col_len) return 0;
        int temp_ans = INT_MAX;


        // moving down
        if(col + 1 != col_len) temp_ans = min(temp_ans,  grid[row][col + 1] + backtrack(grid, row, col + 1, cost + grid[row][col + 1], k));

        // moving right
        if(row + 1 != row_len) temp_ans = min(temp_ans,  grid[row + 1][col] + backtrack(grid, row + 1, col, cost + grid[row + 1][col], k));

        // teleporting 
        if(k){
            int size = indexes_map[grid[row][col]].size();
            for(int idx = 0 ; idx < size ; idx++){
                int nr = indexes_map[grid[row][col]][idx].first;
                int nc = indexes_map[grid[row][col]][idx].second;
                if(nr == row && nc == col) continue;
                temp_ans = min(temp_ans,  0 + backtrack(grid, nr, nc, cost, k - 1));
            }
        }
        return temp_ans;

    }

    int memoization(vector<vector<int>> & grid, int row, int col, int k){
        if(row == row_len - 1 && col == col_len - 1) return 0;

        if(dp[row][col][k] != -1) return dp[row][col][k];

        int temp_ans = INT_MAX;

        // moving down
        if(col + 1 < col_len){
            temp_ans = min(temp_ans, memoization(grid, row, col + 1, k) + grid[row][col + 1]);
        }

        // moving right
        if(row + 1 < row_len){
            temp_ans = min(temp_ans, memoization(grid, row + 1, col, k) + grid[row + 1][col]);
        }

        // teleportation
        if(k){
            int size = indexes_map.size();
            for(int idx = grid[row][col] ; idx >= 0 ; idx--){
                if(indexes_map[idx].size() > 0){
                    for(auto [nr, nc] : indexes_map[idx]){
                        if(nr == row && nc == col) continue;
                        temp_ans = min(temp_ans, memoization(grid, nr, nc, k - 1) + 0);
                    }
                }
            }
        }

        return dp[row][col][k] = temp_ans;
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {
        // int m = grid.size();
        // int n = grid[0].size();
        // row_len = m;
        // col_len = n;
        // set<int> val_set;
        // for(int row = 0 ; row < m ; row++){
        //     for(int col = 0 ; col < n ; col++){
        //         indexes_map[grid[row][col]].push_back({row, col});
        //         val_set.insert(grid[row][col]);
        //     }
        // }

        // // return backtrack(grid, 0, 0, 0, k);

        // // memoization also gives us the tle so we can procede with Dijkstra
        // // dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // // return memoization(grid, 0, 0, k);

        // vector<int> unique_vals(val_set.begin(), val_set.end());
        // sort(unique_vals.begin(), unique_vals.end());

        // // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        // vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k+1,false)));

        // // unordered_map<int, vector<bool>> teleport_used;
        // // for(int val : unique_vals)
        // //     teleport_used[val] = vector<bool>(k+1, false);

        // vector<bool> teleport_used(k+1, false);

        // // pq.push({0, {0, 0}});
        // pq.push({0, k, 0, 0});
        // while(!pq.empty()){
        //     // int [cost, [row, col]] = pq.top();
        //     auto [cost, rem_teleport, row, col] = pq.top();
        //     pq.pop();
        //     if(vis[row][col][rem_teleport]) continue;

        //     vis[row][col][rem_teleport] = true;

        //     if(row == m - 1 && col == n - 1) return cost;

        //     // moving downw
        //     if(col + 1 < n) pq.push({cost + grid[row][col + 1], rem_teleport, row, col + 1});

        //     // moving right
        //     if(row + 1 < m) pq.push({cost + grid[row + 1][col], rem_teleport, row + 1, col});

        //     // if(rem_teleport){
        //     //     int size = indexes_map.size();
        //     //     for(int idx = grid[row][col] ; idx >= 0 ; idx--){
        //     //         if(indexes_map[idx].size() > 0){
        //     //             for(auto [nr, nc] : indexes_map[idx]){
        //     //                 if(nr == row && nc == col) continue;
        //     //                 pq.push({cost, rem_teleport - 1, nr, nc});
        //     //             }
        //     //         }
        //     //     }
        //     // }


        //    if(rem_teleport > 0){
        //         // teleport to all cells with value <= current
        //         for(int val : unique_vals){
        //             if(val > grid[row][col]) break;
        //             for(auto [nr,nc] : indexes_map[val]){
        //                 if(nr == row && nc == col) continue;
        //                 if(!vis[nr][nc][rem_teleport-1])
        //                     pq.push({cost, rem_teleport-1, nr, nc}); // teleport free
        //             }
        //         }
        //     }
        // }

        // return -1;

        int n = grid.size(), m = grid[0].size();
        vector<tuple<int, int, int>> vals(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vals[i * m + j] = {grid[i][j], i, j};
            }
        }
        sort(vals.rbegin(), vals.rend());
        vector available(k, vals);

        
        using tr = tuple<int, int, int, int>;
        priority_queue<tr, vector<tr>, greater<>> pq;
        vector shortest(n, vector(m, vector<int>(k + 1, INT_MAX/2)));
        pq.push({shortest[0][0][0] = 0, 0, 0, 0});

        while(!pq.empty()) {
            auto [cost, i, j, t] = pq.top();
            pq.pop();
            if(cost > shortest[i][j][t] || (t > 0 && cost >= shortest[i][j][t - 1])) continue;
            if(i == n - 1 && j == m - 1) return cost;

            if(i + 1 < n) {
                int newCost = cost + grid[i + 1][j];
                if(newCost < shortest[i + 1][j][t]) {
                    pq.push({shortest[i + 1][j][t] = newCost, i + 1, j, t});
                }
            }
            
            if(j + 1 < m) {
                int newCost = cost + grid[i][j + 1];
                if(newCost < shortest[i][j + 1][t]) {
                    pq.push({shortest[i][j + 1][t] = newCost, i, j + 1, t});
                }
            }

            if(t < k) {
                while(!available[t].empty() && get<0>(available[t].back()) <= grid[i][j]) {
                    auto& [_, ni, nj] = available[t].back();
                    if(cost < shortest[ni][nj][t + 1]) {
                        pq.push({shortest[ni][nj][t + 1] = cost, ni, nj, t + 1});
                    }
                    available[t].pop_back();
                }
                for(int p = t+1; p < k; p++) {
                    while(!available[p].empty() && get<0>(available[p].back()) <= grid[i][j]) {
                        available[p].pop_back();
                    }
                }
            }
        }
        unreachable();
    }
};