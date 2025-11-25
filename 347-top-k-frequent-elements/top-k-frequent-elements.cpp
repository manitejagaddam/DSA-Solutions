class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int ele : nums) mpp[ele]++;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq(mpp.begin(), mpp.end());
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>> pq;
        for(auto it : mpp){
            cout << it.first << " " << it.second << endl;
        }
        for(auto it : mpp){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while(k){
            int ele = pq.top().second;
            pq.pop();
            ans.push_back(ele);
            k--;
        }
        return ans;
    }
};