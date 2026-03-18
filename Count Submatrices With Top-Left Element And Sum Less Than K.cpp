 int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));

        int count = 0;

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] -
                                  prefixSum[i - 1][j - 1] + grid[i - 1][j - 1];

                if (prefixSum[i][j] <= k) {
                    ++count;
                }
            }
        }

        return count;
    }
