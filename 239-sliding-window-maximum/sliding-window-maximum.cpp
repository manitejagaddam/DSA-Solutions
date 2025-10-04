class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int len = nums.size();
        for(int idx = 0 ; idx < len; idx++){
            pq.push({nums[idx], idx});

            if(idx >= k - 1){
                while(pq.top().second <= idx - k){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};