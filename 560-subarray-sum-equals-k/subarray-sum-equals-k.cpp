class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int ele : nums){
            sum += ele;
            int req = sum - k;
            count += mpp[req];
            mpp[sum]++;
        }
        return count;
    }
};