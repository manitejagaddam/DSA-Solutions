class Solution {

private:
    void solve(vector<vector<int>> & image, vector<vector<int>> & ans, vector<pair<int, int>> & directions, int row, int col, int color, int iniColor){
        int m = image.size();
        int n = image[0].size();
        ans[row][col] = color;
        for(auto i : directions){
            int nrow = row + i.first;
            int ncol = col + i.second;

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                solve(image, ans, directions, nrow, ncol, color, iniColor);
            }

        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        solve(image, ans, directions, sr, sc, color, iniColor);
        return ans;
    }
};