class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        
        auto getSum = [&](int i) {
            return prefix[i + k] - prefix[i];
        };
        
        // Step 2: Best left positions
        vector<int> left(n, 0);
        int best = 0;
        for (int i = 0; i <= n - k; i++) {
            if (getSum(i) > getSum(best))
                best = i;
            left[i] = best;
        }
        
        // Step 3: Best right positions
        vector<int> right(n, 0);
        best = n - k;
        for (int i = n - k; i >= 0; i--) {
            if (getSum(i) >= getSum(best))
                best = i;
            right[i] = best;
        }
        
        // Step 4: Try middle window
        vector<int> ans(3, 0);
        int maxSum = 0;
        for (int j = k; j <= n - 2*k; j++) {
            int i = left[j - k];
            int l = right[j + k];
            int total = getSum(i) + getSum(j) + getSum(l);
            if (total > maxSum) {
                maxSum = total;
                ans = {i, j, l};
            }
        }
        
        return ans;
    }
};
