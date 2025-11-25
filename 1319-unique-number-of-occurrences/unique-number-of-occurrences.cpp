class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(int ele : arr) mpp[ele]++;
        unordered_map<int, int> mpp2;
        for(auto it : mpp){
            if(mpp2.count(it.second)) return false;
            mpp2[it.second]++;
        }
        return true;
    }
};