class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // vector<int> ans;
        // int len = nums.size();
        // for(int idx = 1 ; idx <= len ; idx++){
        //     if(nums[idx - 1] != idx) ans.push_back(idx);
        // }
        // return ans;
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;
        int len = nums.size();
        for(int ele = 1 ; ele <= len ; ele++){
            if(!st.count(ele)) ans.push_back(ele);
        }
        return ans;
    }
};