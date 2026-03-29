class Solution {

private:
    bool canPartitionArray(vector<long long> nums, long long target){
        int n = nums.size();
        long long prefixSum = 0;
        for(int idx = 0 ; idx < n - 1 ; idx++){
            prefixSum += nums[idx];
            if(prefixSum == target) return true;
        }
        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> rowSum(m, 0), colSum(n, 0);
        for(int row = 0 ; row < m ; row++){
            long long tempSum = 0;
            for(int col = 0 ; col < n ; col++){
                tempSum += grid[row][col];
            }
            rowSum[row] = tempSum;
        }

        for(int col = 0 ; col < n ; col++){
            long long tempSum = 0;
            for(int row = 0 ; row < m ; row++){
                tempSum += grid[row][col];
            }
            colSum[col] = tempSum;
        }

        // for(auto it : rowSum)
        //     cout << it << " ";
        // cout << endl;

        // for(int it : colSum)
        //     cout << it << " ";
        // cout << endl;

        long long target = accumulate(rowSum.begin(), rowSum.end(), 0LL);

        cout << target;

        if(target % 2 == 1) return false;

        return canPartitionArray(rowSum, target / 2) || canPartitionArray(colSum, target / 2);
    }
};