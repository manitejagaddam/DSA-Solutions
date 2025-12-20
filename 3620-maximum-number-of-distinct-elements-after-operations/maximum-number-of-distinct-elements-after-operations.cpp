class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int prev = INT_MIN; 
        
        for(int num : nums) {
            int minVal = num - k;
            int maxVal = num + k;
            
            int target = max(minVal, prev + 1);
            
            if(target <= maxVal) {
                prev = target;
                count++;
            }
        }
        
        return count;
    }
};