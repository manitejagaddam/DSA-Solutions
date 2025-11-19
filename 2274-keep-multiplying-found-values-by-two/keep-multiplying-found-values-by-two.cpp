class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(nums.begin(), nums.end());
        int size = nums.size();

        while(size){
            if(!st.count(original)) return original;
            original *= 2;
        }
        return original;
    }
};