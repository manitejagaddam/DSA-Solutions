class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<long, long> adj;
        long nov = edges.size(); // no of vertices
        long maxVal = 0;
        long maxVertex = 0;
        for(int idx = 0 ; idx < nov ; idx++){
            adj[edges[idx]] += idx;
            long curr_val = adj[edges[idx]];
            if(maxVal == curr_val){
                maxVertex = maxVertex > edges[idx] ? edges[idx] : maxVertex;
            }
            else if(maxVal < curr_val){
                maxVertex = edges[idx];
                maxVal = curr_val;
            }
        }
        for(auto it : adj){
            cout << it.first << " -> " << it.second << endl;
        }

        return maxVertex;

    }
};