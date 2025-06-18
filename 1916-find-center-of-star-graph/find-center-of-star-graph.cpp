class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // thsi is for the multiple star connections like having more nodes connected

        // unordered_map<int, int> mpp;
        // for(auto it : edges){
        //     int u = it[0];
        //     int v = it[1];
        //     mpp[u]++;
        //     mpp[v]++;
        // }
        // for(auto it : mpp){
        //     if(it.second == mpp.size() - 1) return it.first;
        // }
        // return -1;

        // OPTIMAL according to the question

        // int u1 = edges[0][0];
        // int u2 = edges[1][0];
        // int v1 = edges[0][1];
        // int v2 = edges[1][1];

        // if(u1 == u2 || u1 == v2) return u1;
        // return u2;

        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];
        
        // The common node in both edges is the center
        if (a == c || a == d) return a;
        return b;

    }
};