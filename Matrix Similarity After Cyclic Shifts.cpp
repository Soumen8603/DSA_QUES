 bool areSimilar(vector<vector<int>>& mat, int k) {
        int numRows = mat.size();
        int numCols = mat[0].size();

        k %= numCols;

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (row % 2 == 1) {
                    int shiftedCol = (col + k) % numCols;
                    if (mat[row][col] != mat[row][shiftedCol]) {
                        return false;
                    }
                } else {
                    int shiftedCol = (col - k + numCols) % numCols;
                    if (mat[row][col] != mat[row][shiftedCol]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
