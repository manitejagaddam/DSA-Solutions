class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(int idx = 0 ; idx < k ; idx++){
            pq.push({nums[idx], idx});
        }
        ans.push_back(pq.top().first);
        int len = nums.size();
        for(int idx = k ; idx < len ; idx++){
            pq.push({nums[idx], idx});
            while(!pq.empty() && pq.top().second <= idx - k) pq.pop();
            int ele = pq.top().first;
            ans.push_back(ele);
        }
        return ans;
    }
};