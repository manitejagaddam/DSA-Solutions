class Solution {

private:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }

public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        int minLen = INT_MAX;
        int one_count = 0;
        for(int num : nums) 
            if(num == 1) one_count++;
    
        if(one_count) return len - one_count;

        for(int i = 0 ; i < len ; i++){
            int val = nums[i];
            for(int j = i ; j < len ; j++){
                val = gcd(val, nums[j]);

                if(val == 1){
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        if(minLen == INT_MAX) return -1;

        return len - 1 + minLen - 1;






    }
};