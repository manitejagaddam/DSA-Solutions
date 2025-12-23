class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums1.size(); i++) {
            if(count(nums2.begin(), nums2.end(), nums1[i]) > 0) count1++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(count(nums1.begin(), nums1.end(), nums2[i]) > 0) count2++;
        }

        vector<int> res;
        res.push_back(count1);
        res.push_back(count2);

        return res;
    }
};