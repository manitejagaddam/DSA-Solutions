class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mpp;
        vector<string> ans;
        int mini = INT_MAX;
        
        for (int i = 0; i < list1.size(); i++) {
            mpp[list1[i]] = i;
        }
        
        for (int i = 0; i < list2.size(); i++) {
            if (mpp.find(list2[i]) != mpp.end()) {
                int sum = mpp[list2[i]] + i;
                if (sum < mini) {
                    mini = sum;
                    ans.clear();
                    ans.push_back(list2[i]);
                } else if (sum == mini) {
                    ans.push_back(list2[i]);
                }
            }
        }
        
        return ans;
    }
};