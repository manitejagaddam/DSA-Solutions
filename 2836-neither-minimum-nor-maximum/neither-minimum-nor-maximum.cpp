class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2) return -1;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for(int ele : nums){
            if(ele != mini && ele != maxi) return ele;
        }
        return -1;
    }
};