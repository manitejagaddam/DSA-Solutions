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
            // cout << "req : " << req << "    mpp[req] : " << mpp[req] << "   sum : " << sum << "   mpp[sum] : " << mpp[sum] << endl;
            count += mpp[req];
            mpp[sum]++;
        }
        for(auto it : mpp){
            cout << it.first << " " << it.second << endl;
        }
        return count;
    }
};