class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mpp;
        for(int i : nums) 
            if(i >= 0) 
                mpp[i]++;
        int idx = 1;
        for(auto it : mpp){
            cout << idx << " ";
            if(mpp.count(idx) == 0) return idx;
            idx++;
        }
        return idx;
    }
};