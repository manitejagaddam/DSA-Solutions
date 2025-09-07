class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // queue<pair<int, int>> q;

        pq.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(time < dist[node]) continue;

            for(auto it : adj[node]){
                int nextNode = it.first;
                int weight = it.second;
                if(weight + time < dist[nextNode]){
                    dist[nextNode] = weight + time;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int maxDelay = 0;
        dist[0] = 0;
        for(int currDelay : dist) {
            if(currDelay == INT_MAX) return -1;
            maxDelay = maxDelay < currDelay ? currDelay : maxDelay;
        }


        return maxDelay;











    }
};