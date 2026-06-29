class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(auto it : accounts){
            maxi = max(maxi, accumulate(it.begin(), it.end(), 0));
        }   

        return maxi;
    }
};