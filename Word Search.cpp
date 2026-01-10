class Solution {
private:
    bool solve(vector<vector<char>>& board, int row, int col, int rowSize,
               int colSize, string word, int index) {
        if (index == word.size()) {
            return true;
        }
        if (row < 0 || col < 0 || row >= rowSize || col >= colSize ||
            board[row][col] != word[index])
            return false;
        
        char temp = board[row][col];
        board[row][col] = '#';

        bool found =  solve(board, row - 1, col, rowSize, colSize, word, index+1) ||
               solve(board, row, col - 1, rowSize, colSize, word, index+1) ||
               solve(board, row + 1, col, rowSize, colSize, word, index+1) ||
               solve(board, row, col + 1, rowSize, colSize, word, index+1);

        board[row][col] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int index = 0;
        int m = board.size(), n = board[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == word[0]){
                    if(solve(board,i,j,m,n,word,0))return true;
                }
            }
        }

        return false;
    }
};
