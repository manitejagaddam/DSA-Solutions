class Solution {

private:
    int countNeg(vector<int> & nums){
        int len = nums.size();
        // for(int i : nums) cout << i << " ";
        cout << endl;
        for(int i = 0 ; i < len ; i++){
            if(nums[i] < 0) return len - i;
        }
        return 0;
    }

public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int len = grid.size();
        for(int i = 0 ; i < len ; i++){
            count += countNeg(grid[i]);
        }
        return count;
    }
};