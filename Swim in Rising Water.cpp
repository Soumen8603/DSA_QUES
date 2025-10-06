class Solution {
public:
    vector<int> parent;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n * n);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

        vector<int> heightToIndex(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                heightToIndex[grid[i][j]] = i * n + j;
            }
        }

        vector<int> directions = {-1, 0, 1, 0, -1};

        for (int time = 0; time < n * n; ++time) {
            int currentIndex = heightToIndex[time];
            int row = currentIndex / n;
            int col = currentIndex % n;

            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] <= time) {
                    int adjacentIndex = newRow * n + newCol;
                    parent[find(adjacentIndex)] = find(currentIndex);
                }

                if (find(0) == find(n * n - 1)) {
                    return time;
                }
            }
        }

        return -1;
    }

private:
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

};
