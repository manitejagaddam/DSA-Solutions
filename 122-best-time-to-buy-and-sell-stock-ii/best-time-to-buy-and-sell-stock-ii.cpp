class Solution {

private:
    int tabulation(vector<int> & prices){
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < 2 ; j++){
                if(j){ // holding a stock
                    int sell = prices[i] + dp[i + 1][0];
                    int buy = dp[i + 1][1];
                    dp[i][j] = max(sell, buy);
                }else{ // not holding a stock
                    int buy = dp[i + 1][0];
                    int sell = -prices[i] + dp[i + 1][1];

                    dp[i][j] = max(buy, sell);
                }
            }
        }

        return dp[0][0];

    }

public:
    int maxProfit(vector<int>& prices) {

        return tabulation(prices);
        
        int profit = 0;
        for(int i = 1 ; i< prices.size() ; i++){
            if(prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        }
        
        return profit;
    }
};