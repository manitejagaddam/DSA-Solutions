class Solution {

private:

    void combine_storage(vector<int> & mpp, vector<int> & temp){
        for(int i = 0 ; i < 26 ; i++) mpp[i] += temp[i];
    }

    void dfs(vector<vector<int>> & adj, int node, int parent, vector<int> & ans, string & labels, vector<int> & mpp){
        mpp[labels[node] - 'a']++;
        for(int ele : adj[node]){
            if(ele == parent) continue;
            vector<int> temp_storage(26, 0);
            dfs(adj, ele, node, ans, labels, temp_storage);
            combine_storage(mpp, temp_storage);
        }
        ans[node] = mpp[labels[node] - 'a'];

    }

    void solve(vector<vector<int>> & adj, vector<int> & ans, string & labels){
        vector<int> mpp(26, 0);
        dfs(adj, 0, -1, ans, labels, mpp);
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n,0);
        solve(adj, ans, labels);

        return ans;
    }
};