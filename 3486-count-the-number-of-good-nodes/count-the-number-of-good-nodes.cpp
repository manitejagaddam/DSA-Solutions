class Solution {

private:
    // int dfs(vector<vector<int>> & adj, int node){
    //     if(!node) return 0;
    //     int idx = 0;
    //     vector<int> check(adj[node].size());
    //     for(int adjNode : adj[node]){
    //         check[idx++] = 1 + dfs(adj, adjNode);
    //     }
        
    //     int size = check.size();
    //     for(int i = 0 ; i < size - 1 ; i++){
    //         if(check[i] != check[i + 1]) return 0;
    //     }
    //     return 1;
    // }

//     pair<bool, int> dfs(unordered_map<int, vector<int>>& adj, int node) {
//     if (adj.find(node) == adj.end()) return {true, 1};  // leaf node

//     vector<int> depths;
//     for (int child : adj[node]) {
//         auto [good, depth] = dfs(adj, child);
//         if (!good) return {false, -1};
//         depths.push_back(depth);
//     }

//     for (int i = 1; i < depths.size(); i++) {
//         if (depths[i] != depths[0]) return {false, -1};  // mismatched subtree depths
//     }

//     return {true, depths[0] + 1};  // all children have same depth
// }

    int dfs(int node, int parent) {
        int totalNodes = 0;
        bool isGood = true;
        int subtreeSize = -1;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            int currentSize = dfs(neighbor, node);
            if (subtreeSize == -1) {
                subtreeSize = currentSize;
            } else if (currentSize != subtreeSize) {
                isGood = false;
            }
            totalNodes += currentSize;
        }

        if (isGood) ans++;
        return totalNodes + 1;
    }






public:
    vector<vector<int>> adj; // Use vector of vectors for dynamic sizing
    int ans;
    int countGoodNodes(vector<vector<int>>& edges) {
        // unordered_map<int, vector<int>> mpp;
        // unordered_set<int> children;

        // for(auto it : edges){
        //     int u = it[0];
        //     int v = it[1];
        //     mpp[u].push_back(v);
        //     children.insert(v);
        // }

        //  int root = 0;
        // for (auto& [node, _] : mpp) {
        //     if (children.find(node) == children.end()) {
        //         root = node;
        //         break;
        //     }
        // }

        // return dfs(mpp, root).second;
        // int val = dfs(edges, 0);
        // return ans;



        int n = edges.size() + 1;
        adj.resize(n);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans = 0;
        dfs(0, -1);
        return ans;
        
    }
};