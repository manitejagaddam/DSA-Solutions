class Solution {

private:
    vector<vector<int>> adj;
    unordered_map<int, int> no_edges;
    vector<int> vis;
    int ans = INT_MAX;

    void findTrio(int firstNode, int node, int count, vector<int>& path) {
        if(count > 3) return;

        path.push_back(node);

        
        if(count == 3) {
            int a = path[0], b = path[1], c = path[2];

            
            if(find(adj[a].begin(), adj[a].end(), b) != adj[a].end() &&
               find(adj[a].begin(), adj[a].end(), c) != adj[a].end() &&
               find(adj[b].begin(), adj[b].end(), c) != adj[b].end()) {

                int totalDegree = no_edges[a] + no_edges[b] + no_edges[c] - 6;
                ans = min(ans, totalDegree);
            }

            path.pop_back();
            return;
        }

        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                findTrio(firstNode, adjNode, count + 1, path);
                vis[adjNode] = 0; 
            }
        }

        path.pop_back();
    }

    void dfs(int node){
        vis[node] = 1;
        vector<int> path;
        findTrio(node, node, 1, path);

        for(int adjNode : adj[node]){
            if(!vis[adjNode]) dfs(adjNode); 
        }
    }

public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        adj.resize(n + 1, vector<int>(n + 1, 0));
        vis.resize(n + 1, 0);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            // adj[u].push_back(v);
            // adj[v].push_back(u);
            adj[u][v] = 1;
            adj[v][u] = 1;
            no_edges[u]++;
            no_edges[v]++;
        }

        // for(int node = 1; node <= n; node++){
        //     if(!vis[node]) dfs(node);
        // }
        int res = INT_MAX;
        for(int node1 = 1 ; node1 <= n - 2 ; node1++){
            for(int node2 = node1 + 1 ; node2 <= n - 1 ; node2++){
                if(!adj[node1][node2]) continue;
                for(int node3 = node2 + 1 ; node3 <= n ; node3++){
                    if(adj[node1][node3] && adj[node2][node3]){
                        int tempAns = no_edges[node1] + no_edges[node2] + no_edges[node3] - 6;
                        res = min(res, tempAns);
                    }
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
