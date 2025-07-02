class Solution {
private:
    bool dfs(const string& src, const string& dest,
             unordered_map<string, vector<pair<string, double>>>& adj,
             unordered_set<string>& visited,
             double& result, double currentProduct) {
        
        if (src == dest) {
            result = currentProduct;
            return true;
        }

        visited.insert(src);

        for (auto& neighbor : adj[src]) {
            if (!visited.count(neighbor.first)) {
                if (dfs(neighbor.first, dest, adj, visited, result, currentProduct * neighbor.second)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        for (auto& query : queries) {
            string u = query[0];
            string v = query[1];

            if (adj.find(u) == adj.end() || adj.find(v) == adj.end()) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double result = -1.0;

            dfs(u, v, adj, visited, result, 1.0);
            ans.push_back(result);
        }

        return ans;
    }
};
