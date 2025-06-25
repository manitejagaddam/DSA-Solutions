class Solution {

private:
    bool isPossible(vector<int> & nums, int maxSum, int k){
        int sum = 0;
        int count_sub = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            if(sum > maxSum){
                count_sub++;
                sum = nums[i];
                if(count_sub > k) return false;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;
        for(int i : nums){
            low = max(i, low);
            high += i;
        }
        int ans = high;
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(nums, mid, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};