class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remCounter(k, 0);
        remCounter[0] = 1; // rem[0] = 1 because if the number is divisible directly then we need to add the answer.
        int prefixSum = 0;
        int count = 0;
        for(int ele : nums){
            prefixSum += ele;
            int rem = prefixSum % k;
            if(rem < 0) rem += k;
            count += remCounter[rem];
            remCounter[rem]++;
        }
        return count;
    }
};