 int largestSubmatrix(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        for (int row = 1; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (matrix[row][col] == 1) {
                    matrix[row][col] = matrix[row - 1][col] + 1;
                }
            }
        }

        int maxArea = 0;

        for (auto& currentRow : matrix) {
            sort(currentRow.rbegin(), currentRow.rend());

            for (int col = 0; col < numCols; ++col) {
                int currentArea = (col + 1) * currentRow[col];
                maxArea = max(maxArea, currentArea);
            }
        }

        return maxArea;
    }
