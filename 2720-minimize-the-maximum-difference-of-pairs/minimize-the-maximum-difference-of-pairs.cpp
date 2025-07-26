class Solution {

private:
     bool isPossible(vector<int> &nums, int p, int maxDiff) {
        int count = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; // skip both elements since they are paired
            } else {
                i += 1;
            }
        }
        return count >= p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        // sort(nums.begin(), nums.end());
        // vector<int> pairsValues;
        // set<int> st;
        // int idx = 1;
        // for(int i = 0 ; i < p && idx < nums.size() ; i++, idx += 2){
        //     pairsValues.push_back(nums[idx] - nums[idx - 1]);
        // }
        // int maxVal = 0;
        // for(int ele : pairsValues) {
        //     maxVal = maxVal < ele ? ele : maxVal;
        // }
        // return maxVal;



        // map<int, int> mpp;
        // for(int ele : nums){
        //     mpp[ele]++;
        // }
        // vector<int> pairsValues;
        // int maxVal = 0;
        // int prevVal = 0;
        // bool prevFlag = false;
        // for(auto it : mpp){
        //     if(p == 0) return maxVal;
        //     if(it.second > 1){
        //         p--;
        //         continue;
        //     }
        //     if(!prevFlag){
        //         prevVal = it.first;
        //         prevFlag = true;
        //     }else {
        //         int temp = it.first - prevVal;
        //         maxVal = maxVal < temp ? temp : maxVal;
        //         p--;
        //         prevFlag = false;
        //     }
        // }

        // return maxVal;


        sort(nums.begin(), nums.end());
        int len = nums.size();
        int start = 0;
        int end = nums[len - 1] - nums[0];
        int ans = 0;

        while(start <= end){
            int mid = (start + end) / 2;
            if(isPossible(nums, p, mid)){
                end = mid - 1;
                ans = mid;
            }else{
                start = mid + 1;
            }
        }
        return ans;
        
    }
};