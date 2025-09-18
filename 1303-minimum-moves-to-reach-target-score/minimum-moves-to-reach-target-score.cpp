class Solution {

private:
    using DPTable = unordered_map<int, unordered_map<int, int>>;

    int backtrack(int num, int maxDoubles, int count){
        if(num == 0) {
            return 0;
        }
        if(num < 0) return INT_MAX;

        int incr_one = backtrack(num - 1, maxDoubles, count + 1);
        int incr_double = INT_MAX;
        if(maxDoubles && num % 2 == 0)incr_double = backtrack(num / 2, maxDoubles - 1, count + 1);
        return 1 + min(incr_one, incr_double);
    }

    int memoization(int num, int maxDoubles, DPTable & dp){
    
        if (num <= 1) return 0;

        if (dp.find(num) != dp.end() && dp[num].find(maxDoubles) != dp[num].end())
            return dp[num][maxDoubles];

        int dec_one = memoization(num - 1, maxDoubles, dp);

        int divide = INT_MAX;
        if (maxDoubles > 0 && num % 2 == 0) {
            divide = memoization(num / 2, maxDoubles - 1, dp);
        }

        int best = min(dec_one, divide);
        if (best != INT_MAX) best += 1; 

        return dp[num][maxDoubles] = best;
    }

    // int memoization(int num, int maxDoubles, int count, vector<vector<int>> & dp){
    //     if(num == 0) {
    //         return 1;
    //     }
    //     if(num < 0) return INT_MAX;
    //     if(dp[num][maxDoubles] != -1) return dp[num][maxDoubles];

    //     int incr_one = memoization(num - 1, maxDoubles, count + 1, dp);
    //     int incr_double = INT_MAX;
    //     if(maxDoubles && num % 2 == 0)incr_double = memoization(num / 2, maxDoubles - 1, count + 1, dp);
    //     return dp[num][maxDoubles] = 1 + min(incr_one, incr_double);
    // }


public:
    int minMoves(int target, int maxDoubles) {
        // return backtrack(target, maxDoubles, 0);
        // vector<vector<int>> dp(target + 1, vector<int>(maxDoubles + 1, -1));
        // DPTable dp;
        // return memoization(target, maxDoubles, dp);        
        
        int count = 0;
        // while(target){
        //     while(target && target % 2 == 0 && maxDoubles) {
        //         target /= 2;
        //         count++;
        //         maxDoubles--;
        //     }
        //     if(!target) return count - 1;
        //     target--;
        //     count++;
        // }
        // return count - 1;

        while(target && maxDoubles){
            if(target % 2 == 0) {
                target /= 2;
                maxDoubles--;
            }else target--;
            count++;
        }
        return count + target - 1;

        // while(target){
        //     if(target % 2 == 0 && maxDoubles){
        //         target /= 2;
        //         maxDoubles--;
        //     }else {
        //         target--;
        //     }
        //         count++;
        // }
        // return count - 1;
    }
};