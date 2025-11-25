class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int sum = 0;
        for(int ele : gain){
            sum += ele;
            maxi = maxi < sum ? sum : maxi;
        }
        return maxi;
    }
};