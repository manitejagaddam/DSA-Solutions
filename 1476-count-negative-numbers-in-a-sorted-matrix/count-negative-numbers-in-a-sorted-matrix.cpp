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

    int bsCountNeg(vector<int> & nums){
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            // cout << nums[mid] << " ";
            if(nums[mid] >= 0) start = mid + 1;
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        // cout << "  " << ans << " ";
        // cout << endl;

        return ans != -1 ? nums.size() - ans : 0;
    }

public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int len = grid.size();
        for(int i = 0 ; i < len ; i++){
            // count += countNeg(grid[i]);
            count += bsCountNeg(grid[i]);
        }
        return count;
    }
};