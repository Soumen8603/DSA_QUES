 int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> row(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> col(m + 1, vector<long long>(n, 0));
        vector<vector<long long>> diag1(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> diag2(m + 1, vector<long long>(n + 2, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        int maxSize = min(m, n);

        for (int k = maxSize; k >= 2; k--) {
            for (int r = 0; r + k <= m; r++) {
                for (int c = 0; c + k <= n; c++) {

                    long long target = row[r][c + k] - row[r][c];
                    bool ok = true;

                    for (int i = r; i < r + k && ok; i++) {
                        if (row[i][c + k] - row[i][c] != target)
                            ok = false;
                    }

                    for (int j = c; j < c + k && ok; j++) {
                        if (col[r + k][j] - col[r][j] != target)
                            ok = false;
                    }

                    long long d1 = diag1[r + k][c + k] - diag1[r][c];
                    long long d2 = diag2[r + k][c] - diag2[r][c + k];

                    if (ok && d1 == target && d2 == target)
                        return k;
                }
            }
        }

        return 1;
    }
