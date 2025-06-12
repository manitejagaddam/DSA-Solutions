class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mpp;
        for(int i : nums)mpp[i]++;
        
        sort(nums.begin(), nums.end(), [&mpp](int a, int b){
            if(mpp[a] == mpp[b]) return a > b;
            return mpp[a] < mpp[b];
        });

        return nums;


        // vector<int> ans;
        // for(auto i : mpp){
        //     for(int j = 0 ; j < i.second ; j++){
        //         ans.push_back(i.first);
        //     }
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;

        
        // vector<int> ans;
        // set<int> s;
        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(s.find(nums[i]) == s.end()){
        //         for(int j = 0 ; j < mpp[nums[i]] ; j++){
        //             ans.push_back(nums[i]);
        //         }
        //         s.insert(nums[i]);
        //     }
        // }
        // return ans;
    }
};