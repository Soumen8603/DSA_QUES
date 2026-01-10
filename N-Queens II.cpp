class Solution {
private:
    bool issafe(int currRow,int currCol,int n, map<pair<int, int>, int>& mp) {
        for (int i = 0; i < currCol; i++) {
            if (mp.count({currRow, i}) && mp[{currRow, i}] > 0) {
                return false;
            }
        }

        for(int i = currRow,j = currCol;i >= 0 && j >= 0;i--,j--){
             if (mp.count({i, j}) && mp[{i, j}] > 0) {
                return false;
            }
        }
        for(int i = currRow,j = currCol;j >= 0 && i < n;i++,j--){
             if (mp.count({i, j}) && mp[{i, j}] > 0) {
                return false;
            }
        }

        return true;
    }
    int solve(int col, int n,map<pair<int, int>, int> &mp) {
        if (col >= n)
            return 1;
        int total = 0;
        for(int i = 0;i < n;i++){
            if(issafe(i,col,n,mp)){
                mp[{i,col}]++;
                total += solve(col+1,n,mp);
                mp[{i,col}]--;
            }
        }
        return total;
    }

public:
    int totalNQueens(int n) { 
        map<pair<int, int>, int> mp; 
        return solve(0,n,mp);
        }
};
