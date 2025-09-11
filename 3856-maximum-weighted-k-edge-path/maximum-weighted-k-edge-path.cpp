class Solution {

private:
    int ans = -1;

    void dfs(vector<vector<pair<int, int>>> & adj, int node, vector<int> & vis, int k, int t, int sum, int count){
        if (sum >= t) return;
        if(count == k) {
            ans = ans < sum ? sum : ans;
            return;
        }

        vis[node] = 1;
        
        for(auto adjNode : adj[node]){
            if(!vis[adjNode.first]){
                dfs(adj, adjNode.first, vis, k, t, sum + adjNode.second, count + 1);
            }
        }

        vis[node] = 0;
    }


    int memoization(int ind, int num, int sum, vector<vector<pair<int, int>>>& edges,
             unordered_map<string, int>& dp, int k, int t) {
        if (sum < t && num == k)
            return sum;

        string key =
            to_string(ind) + ' ' + to_string(num) + ' ' + to_string(sum);

        if (dp.find(key) != dp.end())
            return dp[key];

        int ans = 0;

        for (int i = 0; i < edges[ind].size(); i++) {
            int v = edges[ind][i].first;
            int w = edges[ind][i].second;
            int nottaken = memoization(v, 0, 0, edges, dp, k, t);
            int taken = 0;
            if (num + 1 <= k && sum + w < t) {
                taken = memoization(v, num + 1, sum + w, edges, dp, k, t);
            }
            ans = max(ans, (max(taken, nottaken)));
        }

        return dp[key] = ans;
    }



public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if(k == 0) return 0;
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // unordered_map<int, vector<pair<int, int>>> adj;
        // for(int edge : edges){
        //     int u = edge[0];
        //     int v = edge[1];
        //     int w = edge[1];

        //     adj[u].push_back({v, w});
        // }

        vector<int> vis(n, 0);

        // for(int idx = 0 ; idx < n ; idx++){
        //     dfs(adj, idx, vis, k, t, 0, 0);
        // }
        // dfs(adj, 0, vis, k, t, 0, 0);

        unordered_map<string, int> dp;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            if (!adj[i].empty())
                temp = memoization(i, 0, 0, adj, dp, k, t);
            ans = max(ans, temp);
        }

        return ans == 0 ? -1 : ans; 
    }
};