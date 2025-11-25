class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        vector<int> ans1, ans2;
        for(int ele : st1)
            if(!st2.count(ele)) ans1.push_back(ele);
        
        for(int ele : st2) 
            if(!st1.count(ele)) ans2.push_back(ele);
        
        return {ans1, ans2};
    }
};