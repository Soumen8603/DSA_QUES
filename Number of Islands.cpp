class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid, int m, int n) {
        if (grid[i][j] == '1') {
            grid[i][j] = '0';

            // up side
            if (i - 1 >= 0) {
                dfs(i - 1, j, grid, m, n);
            }
            // down side
            if (i + 1 < m) {
                dfs(i + 1, j, grid, m, n);
            }
            // left side
            if (j - 1 >= 0) {
                dfs(i, j - 1, grid, m, n);
            }
            // right side
            if (j + 1 < n) {
                dfs(i, j + 1, grid, m, n);
            }
        }
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count += 1;
                    dfs(i, j, grid, m, n);
                }
            }
        }
        return count;
    }
};
