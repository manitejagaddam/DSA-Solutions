class Solution {

private:
    bool dfs(string & s, vector<vector<int>> & adj, vector<int> & vis, vector<int> & path, vector<vector<int>> &count, int & maxi, int node){
        vis[node] = 1;
        path[node] = 1;
        // count[s[node] - 'a']++;
        for(int i : adj[node]){
            if(path[i]) return true;
            if(!vis[i]){
                if(dfs(s, adj, vis, path, count, maxi, i)) return true;
            }

            for (int c = 0; c < 26; ++c) {
                count[node][c] = max(count[node][c], count[i][c]);
            }
        }
        count[node][s[node] - 'a']++;
        maxi = max(maxi, count[node][s[node] - 'a']);
        path[node] = 0;
        return false;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> visited(n, 0);
        vector<int> path(n, 0);
        vector<vector<int>> count(n, vector<int>(26, 0));
        vector<vector<int>> adj(n);
        for(auto i : edges){
           adj[i[0]].push_back(i[1]);
        }

        int maxi = 0;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                if(dfs(colors, adj, visited, path, count, maxi, i)) {
                    return -1;
                }
            }
        }

        return maxi;
    }
};