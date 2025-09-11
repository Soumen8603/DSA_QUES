 void gameOfLife(vector<vector<int>>& board) {
        int rowSize = board.size();
        int colSize = board[0].size();
        int row, col;
        for (row = 0; row < rowSize; row++) {
            
            for (col = 0; col < colSize; col++) {
                int neighbours = 0;
                // check for right neighbours
                if (col + 1 < colSize && board[row][col + 1] % 2 == 1) {
                    neighbours++;
                }
                // check for left neighbours
                if (col - 1 >= 0 && board[row][col - 1] % 2 == 1) {
                    neighbours++;
                }
                // check for up neighbour
                if (row - 1 >= 0 && board[row - 1][col] % 2 == 1) {
                    neighbours++;
                }
                // check for down neighbour
                if (row + 1 < rowSize && board[row + 1][col] % 2 == 1) {
                    neighbours++;
                }
                // check for upper left nrighbour
                if (row - 1 >= 0 && col - 1 >= 0 &&
                    board[row - 1][col - 1] % 2 == 1) {
                    neighbours++;
                }
                // check for upper right nrighbour
                if (row - 1 >= 0 && col + 1 < colSize &&
                    board[row - 1][col + 1] % 2 == 1) {
                    neighbours++;
                }
                // check for down left nrighbour
                if (row + 1 < rowSize && col - 1 >= 0 &&
                    board[row + 1][col - 1] % 2 == 1) {
                    neighbours++;
                }
                // check for down right nrighbour
                if (row + 1 < rowSize && col + 1 < colSize &&
                    board[row + 1][col + 1] % 2 == 1) {
                    neighbours++;
                }
                //living cells will live if they have  2 or 3 living neighbours
                if (board[row][col] == 1 && (neighbours == 2 ||
                    neighbours == 3)) {
                    board[row][col] += 2;
                }
                //dead cells will live if they have exactly 3 living neighbours
                if (board[row][col] == 0 && neighbours == 3) {
                    board[row][col] += 2;
                }
            }
        }

        for (row = 0; row < rowSize; row++) {
            for (col = 0; col < colSize; col++) {
                board[row][col] = (board[row][col] / 2);
            }
        }
    }
