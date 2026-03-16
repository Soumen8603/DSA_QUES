vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> diagonalSumDownRight(rows + 1,
                                                 vector<int>(cols + 2));
        vector<vector<int>> diagonalSumDownLeft(rows + 1,
                                                vector<int>(cols + 2));

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                diagonalSumDownRight[i][j] =
                    diagonalSumDownRight[i - 1][j - 1] + grid[i - 1][j - 1];
                diagonalSumDownLeft[i][j] =
                    diagonalSumDownLeft[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }

        set<int> uniqueSums;

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int maxRadius = min({i - 1, rows - i, j - 1, cols - j});
                uniqueSums.insert(grid[i - 1][j - 1]);

                for (int radius = 1; radius <= maxRadius; ++radius) {
                    int rightEdge = diagonalSumDownRight[i + radius][j] -
                                    diagonalSumDownRight[i][j - radius];
                    int bottomEdge = diagonalSumDownRight[i][j + radius] -
                                     diagonalSumDownRight[i - radius][j];
                    int leftEdge = diagonalSumDownLeft[i][j - radius] -
                                   diagonalSumDownLeft[i - radius][j];
                    int topEdge = diagonalSumDownLeft[i + radius][j] -
                                  diagonalSumDownLeft[i][j + radius];

                    int rhombusSum = rightEdge + bottomEdge + leftEdge +
                                     topEdge - grid[i + radius - 1][j - 1] +
                                     grid[i - radius - 1][j - 1];
                    uniqueSums.insert(rhombusSum);
                }

                while (uniqueSums.size() > 3) {
                    uniqueSums.erase(uniqueSums.begin());
                }
            }
        }

        return vector<int>(uniqueSums.rbegin(), uniqueSums.rend());
    }
