class Solution {

private:

    vector<string> createAns(vector<vector<char>> & grid){
        vector<string> ans;
        for(auto it : grid){
            string s = "";
            for(auto c : it){
                s += c;
            }
            ans.push_back(s);
        }
        return ans;
    }

    bool isSafe(vector<vector<char>> & grid, int row, int col){
        int n = grid.size();
        for(int i = 0 ; i < n ; i++){
            if(grid[i][col] == 'Q' || grid[row][i] == 'Q') return false;
        }

         // Top-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') return false;
        }

        // Top-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') return false;
        }
        
        return true;
    }



    void createNQueenBoard(vector<vector<char>> & grid, vector<vector<string>> & ans, int row){
        if(row == grid.size()){
            ans.push_back(createAns(grid));
            return;
        }
        int n = grid.size();

        for(int col = 0 ; col < n ; col++){
            if(isSafe(grid, row, col)){
                grid[row][col] = 'Q';
                createNQueenBoard(grid, ans, row + 1);
                grid[row][col] = '.';
            }
        }

    }

    void fetchAllPossibleQueens(vector<vector<char>> & grid, vector<vector<string>> & ans){
        // vector<int> vis(grid.size(), 0);
        createNQueenBoard(grid, ans, 0);
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> grid(n, vector<char>(n, '.'));

        fetchAllPossibleQueens(grid, ans);
        return ans;        
    }
};