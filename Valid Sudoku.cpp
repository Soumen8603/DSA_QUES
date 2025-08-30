 bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for (int i = 0; i < 9; i++) {
            vector<bool> check(9, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (check[num - 1]) return false;
                    check[num - 1] = true;
                }
            }
        }

        // column check
        for (int i = 0; i < 9; i++) {
            vector<bool> check(9, false);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    if (check[num - 1]) return false;
                    check[num - 1] = true;
                }
            }
        }

        // 3x3 subgrid check
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                vector<bool> check(9, false);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[row + i][col + j];
                        if (c != '.') {
                            int num = c - '0';
                            if (check[num - 1]) return false;
                            check[num - 1] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
