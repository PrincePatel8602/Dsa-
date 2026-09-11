class Spreadsheet {
public:
    vector<vector<int>> spread;

Spreadsheet(int rows) {
    spread = vector<vector<int>>(rows, vector<int>(26));
}
    
    void setCell(string cell, int value) {
        int col=int(cell[0]-'A');
        int row=stoi(cell.substr(1,cell.size()-1))-1;
        spread[row][col]=value;
    }
    
    void resetCell(string cell) {
         int col=int(cell[0]-'A');
        int row=stoi(cell.substr(1,cell.size()-1))-1;
        spread[row][col]=0;
    }
    
    int getValue(string formula) {
    int sum = 0;
    string a = "";

    for(int i = 1; i <= formula.size(); i++) {
        if(i == formula.size() || formula[i] == '+') {
            
            if(a[0] >= 'A' && a[0] <= 'Z') {
                int col = a[0] - 'A';
                int row = stoi(a.substr(1))-1;
                sum += spread[row][col];
            }
            else {
                sum += stoi(a);
            }

            a = "";
        }
        else {
            a += formula[i];
        }
    }

    return sum;
}
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */