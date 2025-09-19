class Spreadsheet {
    unordered_map<string,int>spread;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        spread[cell] = value;
    }
    
    void resetCell(string cell) {
        spread[cell] = 0;
    }
    
    int getValue(string formula) {
        string first="";
        int index = 1;
        while(formula[index] != '+'){
            first += formula[index];
            index++;
        }
        int res1;
        if(isdigit(first[0])){
            res1 = stoi(first);
        }
        else{
            res1 = spread[first];
        }
        string second="";
        int res2;
        index++;
        while(index < formula.size()){
            second += formula[index];
            index++;
        }
        if(isdigit(second[0])){
            res2 = stoi(second);
        }
        else{
            res2 = spread[second];
        }
        return res1 + res2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
