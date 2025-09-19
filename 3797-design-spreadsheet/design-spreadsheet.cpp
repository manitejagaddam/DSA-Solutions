class Spreadsheet {

private:
    vector<vector<int>> grid;

public:
    Spreadsheet(int rows) {
        grid.resize(rows + 1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = 0;
        int len = cell.length();
        for(int idx = 1 ; idx < len ; idx++){
            row = ((row * 10)) + cell[idx] - '0';
        }
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);        
    }
    
    int getValue(string formula) {
        int idx = 1;
        int len = formula.size();
        long long val1 = 0;
        if(formula[idx] >= '0' && formula[idx] <= '9'){
            while(formula[idx] != '+'){
                val1 = (val1 * 10) + (formula[idx] - '0'); 
                idx++;
            }
        }else{
            int col1 = 0;
            int row1 = 0;
            col1 = formula[idx++] - 'A';
            while(formula[idx] != '+'){
                row1 = (row1 * 10) + (formula[idx] - '0'); 
                idx++;
            }
            val1 = grid[row1][col1];
            cout << "row1 and col1 : " << row1 << " " << col1 << endl;
        }
        idx++;       // skipping the '+' symbol
        long long val2 = 0;
        if(formula[idx] >= '0' && formula[idx] <= '9'){
            while(idx < len){
                val2 = (val2 * 10) + (formula[idx] - '0'); 
                idx++;
            }
        }else{
            int col2 = 0;
            int row2 = 0;
            col2 = formula[idx++] - 'A';
            while(idx < len){
                row2 = (row2 * 10) + (formula[idx] - '0'); 
                idx++;
            }
            val2 = grid[row2][col2];
            cout << "row2 and col2 : " << row2 << " " << col2 << endl;
        }

        cout << val1 << " " << val2 << endl;
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */