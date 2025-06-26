class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int noe = prices.size();
        for(int idx = 0 ; idx < noe - 1 ; idx++){
            profit += prices[idx + 1] - prices[idx] > 0 ? prices[idx + 1] - prices[idx] : 0;
        }
        return profit;
    }
};