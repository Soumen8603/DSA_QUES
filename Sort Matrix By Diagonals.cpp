vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        int startRow = 0;
        int startCol = 0;
        int row, col;
        // For Bottom Left Triangle
        while (startRow < m) {
            row = startRow;
            col = startCol;
            vector<int> input;
            while (row < m && col < n) {
                input.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(input.begin(), input.end(), std::greater<int>());
            row = startRow;
            col = startCol;
            for (int i = 0; i < input.size(); i++) {
                res[row][col] = input[i];
                row++;
                col++;
            }
            startRow++;
        }

        // For Upper Right Triangle
        startRow = 0;
        startCol = 1;
        while (startCol < n) {
            row = startRow;
            col = startCol;
            vector<int> input;
            while (col < n && row < m) {
                input.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(input.begin(), input.end());
            row = startRow;
            col = startCol;
            for (int i = 0; i < input.size(); i++) {
                res[row][col] = input[i];
                row++;
                col++;
            }
            startCol++;
        }
        return res;
    }
