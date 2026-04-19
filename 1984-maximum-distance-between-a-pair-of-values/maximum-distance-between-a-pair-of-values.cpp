class Solution {

private:
    int upperBound(vector<int> & nums, int ele){
        int start = 0;
        int end = nums.size() - 1;
        int ans = 0;

        
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] >= ele){
                ans = mid;
                start = mid + 1;
            }else end = mid - 1;
        }
        return ans;
    }

public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDis = 0;
        int idx = 0;
        for(int ele : nums1){
            int end = upperBound(nums2, ele);
            int currDis = end - idx++;
            // cout << idx << "  " << end << "  " << currDis << endl;
            maxDis = max(maxDis, currDis);
        }
        return maxDis;
    }
};