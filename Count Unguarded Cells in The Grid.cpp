int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = Unguarded
        // 1 = Guarded
        // 2 = Obstacle (Wall or Guard)
        vector<int> grid(m * n, 0);

        // 1. Mark all obstacles
        for (auto& wall : walls) {
            grid[wall[0] * n + wall[1]] = 2;
        }
        for (auto& guard : guards) {
            grid[guard[0] * n + guard[1]] = 2;
        }

        // 2. Simulate guarding
        for (auto& guard : guards) {
            int gRow = guard[0];
            int gCol = guard[1];

            // Look to left side
            int col = gCol - 1;
            while (col >= 0) {
                int idx = gRow * n + col;
                if (grid[idx] == 2) break; // ONLY stop for obstacles
                if (grid[idx] == 0) grid[idx] = 1; // Mark if unguarded
                // If grid[idx] is 1, do nothing and continue
                col--;
            }

            // Look to right side
            col = gCol + 1;
            while (col < n) {
                int idx = gRow * n + col;
                if (grid[idx] == 2) break;
                if (grid[idx] == 0) grid[idx] = 1;
                col++;
            }

            // Look to up side
            int row = gRow - 1;
            while (row >= 0) {
                int idx = row * n + gCol;
                if (grid[idx] == 2) break;
                if (grid[idx] == 0) grid[idx] = 1;
                row--;
            }

            // Look to down side
            row = gRow + 1;
            while (row < m) {
                int idx = row * n + gCol;
                if (grid[idx] == 2) break;
                if (grid[idx] == 0) grid[idx] = 1;
                row++;
            }
        }

        // 3. Count the unguarded cells
        int count = 0;
        for (int i = 0; i < m * n; i++) {
            if (grid[i] == 0) {
                count++;
            }
        }
        return count;
    }
