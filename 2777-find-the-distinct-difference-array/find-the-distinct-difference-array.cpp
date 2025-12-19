class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> suffix;
        for(int ele : nums) suffix[ele]++;
        unordered_map<int, int> prefix;

        vector<int> ans;
        for(int ele : nums){
            prefix[ele]++;
            suffix[ele]--;
            if(suffix[ele] == 0) suffix.erase(ele);
            ans.push_back(prefix.size() - suffix.size());
        }
        return ans;
    }
};