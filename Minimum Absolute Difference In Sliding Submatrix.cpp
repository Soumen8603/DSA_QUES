vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> result(rows - k + 1, vector<int>(cols - k + 1, 0));

        for (int startRow = 0; startRow <= rows - k; ++startRow) {
            for (int startCol = 0; startCol <= cols - k; ++startCol) {

                vector<int> subgridElements;
                for (int row = startRow; row < startRow + k; ++row) {
                    for (int col = startCol; col < startCol + k; ++col) {
                        subgridElements.push_back(grid[row][col]);
                    }
                }

                sort(subgridElements.begin(), subgridElements.end());

                int minDifference = INT_MAX;
                for (int i = 1; i < subgridElements.size(); ++i) {
                    if (subgridElements[i] != subgridElements[i - 1]) {
                        int currentDifference =
                            abs(subgridElements[i] - subgridElements[i - 1]);
                        minDifference = min(minDifference, currentDifference);
                    }
                }

                result[startRow][startCol] =
                    (minDifference == INT_MAX) ? 0 : minDifference;
            }
        }

        return result;
    }
