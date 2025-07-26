class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int len = arr.size();
        int minDiff = INT_MAX;
        // for(int idx = 1 ; idx < len ; idx++){
        //     minDiff = minDiff > arr[idx] - arr[idx - 1] ? arr[idx] - arr[idx - 1] : minDiff;
        // }
        // for(int idx = 1 ; idx < len ; idx++){
        //     if(arr[idx] - arr[idx - 1] == minDiff){
        //         ans.push_back({arr[idx - 1], arr[idx]});
        //     }
        // }
        // return ans;


        for(int idx = 1 ; idx < len ; idx++){
            int diff = arr[idx] - arr[idx - 1];
            if(diff < minDiff){
                ans.clear();
                ans.push_back({arr[idx - 1], arr[idx]});
                minDiff = diff;
            }else if(diff == minDiff) ans.push_back({arr[idx - 1], arr[idx]});
        }
        return ans;

    }
};