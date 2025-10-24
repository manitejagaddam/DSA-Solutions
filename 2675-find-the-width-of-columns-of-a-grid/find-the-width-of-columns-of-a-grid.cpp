class Solution {

private:
    int findLenOfInteger(int num){
        int len = 0;
        if(num < 0){
            len++;
            num = -num;
        }
        while(num){
            len++;
            num /= 10;
        }
        return len;
    }

public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        
        int m = grid.size();
        int n = grid[0].size();
        for(int col = 0 ; col < n ; col++){
            int maxLen = 1;
            for(int row = 0 ; row < m ; row++){
                int tempLen = findLenOfInteger(grid[row][col]);
                maxLen = maxLen < tempLen ? tempLen : maxLen;
            }
            ans.push_back(maxLen);
        }
        return ans;
    }
};