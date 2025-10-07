
class Solution {

private:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second; 
        }
    };


public:
    vector<int> avoidFlood(vector<int>& rains) {
        // int len = rains.size();
        // vector<int> ans(len, -1);
        // unordered_map<int, vector<int>> mpp;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        // vector<int> zero_idx;

        // set<int>
        // int can_flood = 0;

        // for(int idx = 0 ; idx < len ; idx++){

        // }

        // for(int idx = 0 ; idx < len ; idx++){
            
        //     if(rains[idx] == 0) zero_idx.push_back(idx);
        //     else{
        //         mpp[rains[idx]].push_back(idx);
        //         if(mpp[rains[idx]].size() > 1) can_flood++;
        //     }
        // }
        // int zero_count = zero_idx.size();
        // if(zero_count < can_flood) return {};
        // for(auto [ele, freq] : mpp){
        //     pq.push({freq.size(), ele});
        // }

        // for(int idx : zero_idx){
        //     if(!pq.empty()){
        //         auto [freq, ele] = pq.top();
        //         pq.pop();

        //         ans[idx] = ele;
        //         if(freq > 1) pq.push({freq - 1, ele});
        //     }else ans[idx] = 1;
        // }

        // return ans;



        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> lake_last_filled; // lake -> last day it got water
        set<int> dry_days; // indices of days with 0
        unordered_map<int, queue<int>> future; // lake -> next rain days

        // Pre-fill future days
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) future[rains[i]].push(i);
        }

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dry_days.insert(i); // available dry day
                ans[i] = 1; // temporary
            } 
            else {
                int lake = rains[i];
                future[lake].pop(); // this rain happens now

                if (lake_last_filled.count(lake)) {
                    // we need to dry it before today
                    auto it = dry_days.lower_bound(lake_last_filled[lake]);
                    if (it == dry_days.end()) return {}; // no available day
                    ans[*it] = lake; // dry this lake
                    dry_days.erase(it);
                }

                lake_last_filled[lake] = i;
            }
        }

        return ans;

    }
};