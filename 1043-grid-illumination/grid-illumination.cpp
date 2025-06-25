class Solution {

private:

    struct pairHash{
        size_t operator()(const pair<int, int> & p) const{
            return p.first ^ p.second;
        }
    };




    void fillLights(vector<vector<int>> & grid, int row, int col){
        int n = grid.size();

        
        for(int i = 0 ; i < n ; i++) grid[i][col] += 1;
        for(int i = 0 ; i < n ; i++) grid[row][i] += 1;
        for(int i = row, j = col ; i < n && j < n ; i++, j++) grid[i][j] += 1;
        for(int i = row, j = col ; i >= 0 && j >= 0 ; i--, j--) grid[i][j] += 1;
        for(int i = row, j = col ; i < n && j >= 0 ; i++, j--) grid[i][j] += 1;
        for(int i = row, j = col ; i >= 0 && j < n ; i--, j++) grid[i][j] += 1;

        grid[row][col] -= 5;
        
    }

    void printLights(vector<vector<int>> & grid){
        for(auto i : grid){
            for(auto j : i) cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }

    void turnOffAllLights(vector<vector<int>> & grid, int row, int col){
        int n = grid.size();
        int temp_row = row;
        int temp_col = col;
        int prev_val = grid[row][col];

        
        for(int i = 0 ; i < n ; i++) grid[i][col] -= 1;
        for(int i = 0 ; i < n ; i++) grid[row][i] -= 1;
        for(int i = row, j = col ; i < n && j < n ; i++, j++) grid[i][j] -= 1;
        for(int i = row, j = col ; i >= 0 && j >= 0 ; i--, j--) grid[i][j] -= 1;
        for(int i = row, j = col ; i < n && j >= 0 ; i++, j--) grid[i][j] -= 1;
        for(int i = row, j = col ; i >= 0 && j < n ; i--, j++) grid[i][j] -= 1;
        
        grid[row][col] += 5;
        // grid[temp_row][temp_col] = prev_val - 1;
    }

    bool isLamp(int row, int col, set<vector<int>> & st){
        auto it = st.find({row, col});
        if (it != st.end()) {
            st.erase(it);
            return true;
        }
        return false;
    }



    void turnOffLights(vector<vector<int>> & grid, int row, int col, set<vector<int>> & st){
        int n = grid.size();
        for(int i = -1 ; i <= 1 ; i++){
            for(int j = -1 ; j <= 1 ; j++){
                int r = row + i;
                int c = col + j;
                if(r >= 0 && c >= 0 && r < n && c < n && isLamp(r, c, st)){
                    turnOffAllLights(grid, r, c);
                }
            }
        }
    }

public:
    // // This is giving Us the TLE 
    // vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    //     vector<vector<int>> grid(n, vector<int>(n, 0));
    //     set<vector<int>> st;
    //     for(auto lamp : lamps){
    //         int row = lamp[0];
    //         int col = lamp[1];
    //         if(st.count({row, col}) > 0) continue;
    //         st.insert({row, col});
    //         fillLights(grid, row, col);
    //     }

    //     vector<int> ans;
    //     for(auto query : queries){
    //         int row = query[0];
    //         int col = query[1];

    //         if(grid[row][col]) ans.push_back(1);
    //         else ans.push_back(0);

    //         printLights(grid);

    //         turnOffLights(grid, row, col, st);
    //     }

    //     return ans;
    // }


    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        /*
            see we are using map ds because to avoid the grid searching 
            actually here we are updating all the rows and columns and diagonals in grid 
            but here we are just storing the row, col, dignola numbers 
            as we can see in the above the fill part of the code it is actually entire row is constant, 
            entire col is constant like
            for(int i = 0 ; i < n ; i++) grid[row][i] = 1;
            for(int i = 0 ; i < n ; i++) grid[i][col] = 1;
            instead of this we are just storing the value in row as i and in col as c

            while erasing also we are eraing all the rows 
            so to avoid this we can just remove the particular row number or column number form their particular ds
        */



        unordered_map<int, int> row, col, dig, anti_dig;
        unordered_set<pair<int, int>, pairHash> lights;
        for(auto it : lamps){
            int r = it[0];
            int c = it[1];
            if(lights.count({r, c}) > 0) continue;
            lights.insert({r, c});
            row[r]++;
            col[c]++;
            dig[r - c]++;
            anti_dig[r + c]++;
        }
        

        vector<int> ans;
        for(auto query : queries){
            int r = query[0];
            int c = query[1];
            if(row[r] > 0 || col[c] > 0 || dig[r - c] > 0 || anti_dig[r + c] > 0) ans.push_back(1);
            else ans.push_back(0);

            // // Used for debugging
            // cout << "Rows : " << endl;
            // for(auto i : row)cout << i.first << " -> " << i.second << endl;
            // cout << endl;
            // cout << "cols : " << endl;
            // for(auto i : col)cout << i.first << " -> " << i.second << endl;
            // cout << endl;
            // cout << "Dig : " << endl;
            // for(auto i : dig)cout << i.first << " -> " << i.second << endl;
            // cout << endl;
            // cout << "Anti-dig : " << endl;
            // for(auto i : anti_dig)cout << i.first << " -> " << i.second << endl;
            // cout << endl;


            for(int i = -1 ; i <= 1 ; i++){
                for(int j = -1 ; j <= 1 ; j++){
                    int nr = r + i;
                    int nc = c + j;
                    if(lights.count({nr, nc}) > 0) {
                        lights.erase({nr, nc});
                        row[nr]--;
                        col[nc]--;
                        dig[nr - nc]--;
                        anti_dig[nr + nc]--;
                    }
                }
            }
        }

        return ans;
    }
};