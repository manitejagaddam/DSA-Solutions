class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        for(int ele : nums1){
            if(st2.count(ele)) st2.erase(ele);
        }
        for(int ele : nums2) {
            if(st1.count(ele)) st1.erase(ele);
        }
        vector<int> ans1(st1.begin(), st1.end()), ans2(st2.begin(), st2.end());
        return {ans1, ans2};
    }
};