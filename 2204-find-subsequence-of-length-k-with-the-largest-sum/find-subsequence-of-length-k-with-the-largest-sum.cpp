class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // int n = nums.size();
        // if(k == n) return nums;
        // sort(nums.begin(), nums.end());
        // vector<int> ans;
        // for(int i = n - k ; i < n ; i++){
        //     ans.push_back(nums[i]);
        // }
        // return ans;

        int n = nums.size();
        if(k == n) return nums;
        vector<int> dummy(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i = n - k ; i < n ; i++){
            mpp[nums[i]]++;
        }
        for(int i : dummy){
            if(mpp.find(i) != mpp.end()){
                ans.push_back(i);
                mpp[i]--;
                if(mpp[i] == 0) mpp.erase(i);
            }
        }
        return ans;
    }
};