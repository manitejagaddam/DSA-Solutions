class Solution {

private:
    int smallestEle(vector<int> & nums){
        int smallest_ele = INT_MAX;
        for(int ele : nums){
            smallest_ele = smallest_ele > ele ? ele : smallest_ele;
        }
        return smallest_ele;
    }

public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int idx1 = 0 ; idx1 < nums1.size() ; idx1++){
            for(int idx2 = 0 ; idx2 < nums2.size() ; idx2++){
                if(nums1[idx1] == nums2[idx2]) return nums1[idx1];
            }
        }

        int mini1 = smallestEle(nums1);
        int mini2 = smallestEle(nums2);

        // if(nums1[0] < nums2[0]) return nums1[0] * 10 + nums2[0];
        // return nums2[0] * 10 + nums1[0];

        if(mini1 < mini2) return mini1 * 10 + mini2;
        return mini2 * 10 + mini1;
    }
};