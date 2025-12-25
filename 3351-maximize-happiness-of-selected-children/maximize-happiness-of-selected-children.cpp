class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long toDecrement = 0;
        long long ans = 0;
        int len = happiness.size();
        for(int idx = 0 ; idx < len && k ; idx++, k--, toDecrement++){
            if(happiness[idx] - toDecrement > 0){
                ans += happiness[idx] - toDecrement;
            }else break;
        }
        return ans;
    }
};