class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int oddCount = 0;
        int evenCount = 1;
        int prefixSum = 0;
        for(int ele : arr){
            prefixSum += ele;
            if(prefixSum % 2 == 0){
                ans += oddCount;
                evenCount++;
            }else{
                ans += evenCount;
                oddCount++;
            }
            ans = ans % MOD;
        }
        return ans;

    }
};