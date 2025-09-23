class Solution {

private:

    vector<vector<vector<int>>> dp;

    int backtrack(int idx, vector<int> & nums, int transactionsLeft, bool canBuy, int previousBought){
        if(idx == nums.size()) return 0;
        if(!transactionsLeft) return 0;

        int ans = 0;

        if (canBuy) {
            int buy = backtrack(idx + 1, nums, transactionsLeft, false, nums[idx]) - nums[idx];

            int skip = backtrack(idx + 1, nums, transactionsLeft, true, previousBought);

            ans = max(buy, skip);
        } 
        else {
            int sell = nums[idx] + backtrack(idx + 1, nums, transactionsLeft - 1, true, -1);

            int skip = backtrack(idx + 1, nums, transactionsLeft, false, previousBought);

            ans = max(sell, skip);
        }

        return ans;
    }

    int memoization(int idx, vector<int> & nums, int transactionsLeft, bool canBuy, int previousBought){
        if(idx == nums.size()) return 0;
        if(!transactionsLeft) return 0;

        if (dp[idx][transactionsLeft][canBuy] != -1) return dp[idx][transactionsLeft][canBuy];

        int ans = 0;
        if(canBuy){
            int buy = memoization(idx + 1, nums, transactionsLeft, false, nums[idx]) - nums[idx];

            int skip = memoization(idx + 1, nums, transactionsLeft, true, previousBought);

            ans = max(buy, skip);
        }else{
            int sell = memoization(idx + 1, nums, transactionsLeft - 1, true, -1) + nums[idx];
            int skip = memoization(idx + 1, nums, transactionsLeft, false, previousBought);

            ans = max(sell, skip);
        }

        return dp[idx][transactionsLeft][canBuy] = ans;
    }

public:
    int maxProfit(vector<int>& prices) {
        // return backtrack(0, prices, 2, true, -1);
        //         idx                        transactionsLeft    canBuy
        dp.resize(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));
        return memoization(0, prices, 2, true, -1);
    }
};