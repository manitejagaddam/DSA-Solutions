class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mpp;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            mpp[u]++;
            mpp[v]++;
        }
        for(auto it : mpp){
            if(it.second == mpp.size() - 1) return it.first;
        }
        return -1;
    }
};