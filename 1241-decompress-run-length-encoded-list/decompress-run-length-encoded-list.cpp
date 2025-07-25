class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int noe = nums.size(); // no of elements
        for(int idx = 0 ; idx < noe ; idx += 2){
            int freq = nums[idx];
            int val = nums[idx + 1];
            for(int temp_idx = 0 ; temp_idx < freq ; temp_idx++){
                res.push_back(val);
            }
        }
        return res;
    }
};