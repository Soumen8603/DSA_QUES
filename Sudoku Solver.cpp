class Solution {
private:
    bool backtrack(vector<vector<char>>& board,int row,int col,vector<vector<bool>>&rows,
                    vector<vector<bool>>&cols,vector<vector<bool>>&grid){
                        if(col == 9){
                            col = 0;
                            row++;
                            if(row == 9)return true;
                        }
                        if(board[row][col] != '.'){
                            return backtrack(board,row,col+1,rows,cols,grid);
                        }
                        for(int i = 0;i < 9;i++){
                           
                            int grididx = (row/3) * 3 + col / 3;
                            if(!rows[row][i] && !cols[col][i] && !grid[grididx][i]){
                                board[row][col] = i+'1';
                                rows[row][i] = cols[col][i] = grid[grididx][i] = true;
                                if(backtrack(board,row,col+1,rows,cols,grid))return true;
                                board[row][col] = '.';
                                rows[row][i] = cols[col][i] = grid[grididx][i] = false;
                            }
                        }
                        return false;
                    }
public:
    void solveSudoku(vector<vector<char>>& board) {
         // row check
         vector<vector<bool>> rows(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
            
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    rows[i][num-1] = true;
                }
            }
        }

        // col check
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
            
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    cols[i][num-1] = true;
                }
            }
        }

        // 3x3 subgrid check
         vector<vector<bool>> grid(9, vector<bool>(9, false));
         int count = -1;
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                count++;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[row + i][col + j];
                        if (c != '.') {
                            int num = c - '0';
                            grid[count][num - 1] = true;
                        }
                    }
                }
            }
        }
        backtrack(board, 0, 0, rows, cols, grid);
    }
};
