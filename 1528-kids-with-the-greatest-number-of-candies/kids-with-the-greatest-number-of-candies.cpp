class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_element = 0;
        int len = candies.size();
        for(int candie : candies) max_element = max_element < candie ? candie : max_element;
        vector<bool> ans(len);
        for(int idx = 0 ; idx < len ; idx++){
            ans[idx] = candies[idx] + extraCandies >= max_element;
        }
        return ans;
    }
};