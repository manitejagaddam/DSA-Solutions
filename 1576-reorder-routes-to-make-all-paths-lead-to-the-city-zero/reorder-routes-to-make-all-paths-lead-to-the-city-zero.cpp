class Solution {

private:
    void dfs(vector<vector<int>> & adj, int node, vector<int> & vis, set<pair<int, int>> & st, int & count_dir){
        vis[node] = 1;

        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                // if(st.find({node, adjNode}) != st.end()) count_dir++;
                if(st.count({node, adjNode})) count_dir++;
                dfs(adj, adjNode, vis, st, count_dir);
            } 
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int, int>> st;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            st.insert({u, v});
        }
        int count_dir = 0;
        vector<int> vis(n, 0);
        dfs(adj, 0, vis, st, count_dir);
        return count_dir;
    }
};