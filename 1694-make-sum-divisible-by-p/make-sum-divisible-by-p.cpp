class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        if(sum % p == 0) return 0;
        
        int reqRem = sum % p;

        unordered_map<int, int> prefixRem;
        prefixRem[0] = -1;

        int len = nums.size();
        long long currSum = 0;

        int ans = len;
        for(int idx = 0 ; idx < len ; idx++){
            currSum += nums[idx];
            int currRem = currSum % p;
            int reqVal = (currRem - reqRem + p) % p; // addition of p is to avoid the negative numbers

            if(prefixRem.count(reqVal)){
                ans = min(ans, idx - prefixRem[reqVal]);
            }

            prefixRem[currRem % p] = idx;
        }

        return ans == len ? -1 : ans;
    }
};