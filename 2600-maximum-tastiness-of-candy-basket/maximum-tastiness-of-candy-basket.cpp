class Solution {

private:
    bool isPossible(vector<int> & nums, int k, int req){
        int basket = 1;
        int last_idx = 0;
        int len = nums.size();
        for(int idx = 1 ; idx < len ; idx++){
            if(nums[idx] - nums[last_idx] >= k){
                basket++;
                last_idx = idx;
            }
        }

        return basket >= req;
    }

public:
    int maximumTastiness(vector<int>& price, int k) {
        int ans = 0;
        sort(price.begin(), price.end());
        int start = 0;
        int end = price[price.size() - 1] - price[0];
        while(start <= end){
            int mid = (start + end) / 2;
            if(isPossible(price, mid, k)){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        } 

        return ans;

    }
};