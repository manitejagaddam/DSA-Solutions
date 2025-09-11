class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int idx1 = 0 ; idx1 < nums1.size() ; idx1++){
            for(int idx2 = 0 ; idx2 < nums2.size() ; idx2++){
                if(nums1[idx1] == nums2[idx2]) return nums1[idx1];
            }
        }

        if(nums1[0] < nums2[0]) return nums1[0] * 10 + nums2[0];
        return nums2[0] * 10 + nums1[0];
    }
};