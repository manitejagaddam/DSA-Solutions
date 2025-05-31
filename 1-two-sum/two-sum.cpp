class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            map <int, int> mpp;
            vector<int> ans;
            for(int i = 0 ; i < nums.size() ; i++){
                int required = target - nums[i];
                if(mpp.find(required) != mpp.end()){
                    return {mpp[required], i};
                }
                mpp[nums[i]] = i;
            }
            
            return {};
    }
};