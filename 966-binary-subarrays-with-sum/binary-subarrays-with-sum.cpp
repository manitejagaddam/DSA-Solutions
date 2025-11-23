class Solution {

private:
    int solve(vector<int> & nums, int goal){
        int n = nums.size();
        int l = 0, r = 0, ans = 0;
        int sum = 0;
        while(r < n){
            sum += nums[r];
            while(l <= r && sum > goal){
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            cout << ans << " ";
            r++;
        }
        return ans;
    }


public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        if(goal < 0) return 0;
        return solve(nums, goal) - solve(nums, goal - 1);
        
        
        
        // unordered_map<int, int> count;
        // count[0] = 1;
        // int curr_sum = 0;
        // int total_subarrays = 0;

        // for (int num : nums) {
        //     curr_sum += num;
        //     if (count.find(curr_sum - goal) != count.end()) {
        //         total_subarrays += count[curr_sum - goal];
        //     }
        //     count[curr_sum]++;
        // }

        // return total_subarrays;


    }
};