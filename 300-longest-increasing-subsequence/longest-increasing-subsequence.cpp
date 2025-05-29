#include <bits/stdc++.h>
class Solution {
private:

    int solve(int idx, vector<int> & nums, vector<int> &ans){
        if(idx == nums.size()) return ans.size();

        int i = solve(idx + 1, nums, ans);
        int j = 0;

        if(ans.empty() || ans.back() < nums[idx]){
            ans.push_back(nums[idx]);
            j = solve(idx + 1, nums, ans);
            ans.pop_back();
        }

        return max(i, j);
    }



    void solve(int idx, vector<int> & nums, vector<int> &ans, int &maxi){
        if(idx == nums.size()){
            if(ans.size() > maxi){
                maxi = ans.size();
            }
            // maxi = max(ans.size(), maxi);
            return;
        }

        else{
            if(ans.empty() || ans.back() < nums[idx]){
                ans.push_back(nums[idx]);
                solve(idx + 1, nums, ans, maxi);
                ans.pop_back();
            }
            solve(idx + 1, nums, ans, maxi);
        }
    }


    int memoization(int curr, int prev, vector<int> & nums, vector<vector<int>> &dp){
        if(curr == nums.size()) return 0;

        if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

        int exclude = memoization(curr+ 1, prev, nums, dp);

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + memoization(curr+1, curr, nums, dp);
        }

        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    int tabulation(vector<int> & nums){
        vector<int> dp(nums.size(), 1);

        for(int curr = 0 ; curr < nums.size() ; curr++){
            for(int prev = 0 ; prev < curr ; prev++){
                if(nums[prev] < nums[curr]){
                    dp[curr] = max(dp[curr], dp[prev] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }


public:
    int lengthOfLIS(vector<int>& nums) {
        // int maxi = 0;
        // vector<int> ans;
        // solve(0, nums, ans, maxi);
        // return maxi;
        // return solve(0, nums, ans);
        // vector<vector<int>> dp(nums.size(), vector<int> (nums.size() + 1, -1));
        // return memoization(0 , -1, nums, dp);

        return tabulation(nums);
    }
};