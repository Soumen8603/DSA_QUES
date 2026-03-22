 bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for (int rotationCount = 0; rotationCount < 4; ++rotationCount) {
            vector<vector<int>> rotatedMatrix(n, vector<int>(n));

            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < n; ++col) {
                    rotatedMatrix[row][col] = mat[col][n - row - 1];
                }
            }

            if (rotatedMatrix == target) {
                return true;
            }

            mat = rotatedMatrix;
        }

        return false;
    }
