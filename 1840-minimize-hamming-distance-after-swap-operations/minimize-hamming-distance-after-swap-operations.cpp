// class Solution {


// private:
//     vector<vector<int>> swaps;
//     bool canSwap(int start, int end){
//         queue<int> q;
//         unordered_set<int> st;
//         st.insert(start);
//         q.push(start);
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             for(int neighbourNode : swaps[node]){
//                 if(!st.count(neighbourNode)){
//                     if(neighbourNode == end) return true;
//                     q.push(neighbourNode);
//                     st.insert(neighbourNode);
//                 }
//             }
//         }

//         return false;
//     }


// public:
//     int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
//         int n = source.size();
//         swaps.resize(n + 1);
//         for(auto it : allowedSwaps){
//             swaps[it[0]].push_back(it[1]);
//             swaps[it[1]].push_back(it[0]);
//         }

//         unordered_map<int, pair<int, int>> mpp;
//         for(int idx = 0 ; idx < n ; idx++){
//             mpp[source[idx]].first = idx; 
//         }
//         for(int idx = 0 ; idx < n ; idx++){
//             mpp[target[idx]].second = idx;
//         }

//         for(auto it : mpp){
//             if(it.second.first != it.second.second){
//                 if(canSwap(it.second.first, it.second.second)){
//                     swap(source[it.])
//                 }
//             }
//         }
//         return true;

//     }
// };














class Solution {
private:
    vector<int> fa;
    vector<int> rank;
    // path compression
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        // merge by rank
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        fa[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        fa.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (auto& pair : allowedSwaps) {
            Union(pair[0], pair[1]);
        }
        unordered_map<int, unordered_map<int, int>> sets;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets[f][source[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};