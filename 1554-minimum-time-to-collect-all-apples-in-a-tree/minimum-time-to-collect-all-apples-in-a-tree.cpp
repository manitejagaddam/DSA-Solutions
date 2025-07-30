class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int time = 0;
        for (int child : adj[node]) {
            if (child == parent) continue;
            int childTime = dfs(child, node, adj, hasApple);
            if (childTime > 0 || hasApple[child]) {
                time += childTime + 2; 
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); 
        }

        return dfs(0, -1, adj, hasApple);
    }
};
