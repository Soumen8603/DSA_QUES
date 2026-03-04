int numSpecial(vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();

        vector<int> rowSum(numRows, 0);
        vector<int> colSum(numCols, 0);

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                rowSum[row] += mat[row][col];
                colSum[col] += mat[row][col];
            }
        }

        int specialCount = 0;

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (mat[row][col] == 1 && rowSum[row] == 1 &&
                    colSum[col] == 1) {
                    specialCount++;
                }
            }
        }

        return specialCount;
    }
