class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> mpp(501, 0);
        for(int i : arr) mpp[i]++;
        for(int i = 500 ; i > 0 ; i--){
            if(mpp[i] == i) return i;
        }
        return -1;
    }
};