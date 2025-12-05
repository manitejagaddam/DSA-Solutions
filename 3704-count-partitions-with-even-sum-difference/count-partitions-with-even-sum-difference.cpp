class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixSum(len, 0);

        prefixSum[0] = nums[0] % 2;
        for(int idx = 1 ; idx < len ; idx++){
            prefixSum[idx] = (prefixSum[idx - 1] + nums[idx]) % 2; 
        }

        int count = 0;
        for(int idx = 1 ; idx < len ; idx++){
            int first = prefixSum[idx];
            int last = abs(prefixSum[len - 1] - first);
            // cout << first << " " << last << endl;
            if(abs(first - last) % 2 == 0) count++;
        }
        return count;

    }
};