class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int req_sum = accumulate(apple.begin(), apple.end(), 0);
        int curr_sum = 0;
        int len = capacity.size();
        sort(capacity.rbegin(), capacity.rend());
        for(int idx = 0 ; idx < len ; idx++){
            curr_sum += capacity[idx];
            if(curr_sum >= req_sum) return idx + 1;
        }
        return -1;
    }
};