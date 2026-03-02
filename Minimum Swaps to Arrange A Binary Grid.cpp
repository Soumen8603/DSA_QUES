class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rightmostOnePosition(n, -1);

        for (int row = 0; row < n; ++row) {
            for (int col = n - 1; col >= 0; --col) {
                if (grid[row][col] == 1) {
                    rightmostOnePosition[row] = col;
                    break;
                }
            }
        }

        int totalSwaps = 0;
        for (int targetRow = 0; targetRow < n; ++targetRow) {
            int foundRow = -1;

            for (int candidateRow = targetRow; candidateRow < n;
                 ++candidateRow) {
                if (rightmostOnePosition[candidateRow] <= targetRow) {
                    totalSwaps += candidateRow - targetRow;
                    foundRow = candidateRow;
                    break;
                }
            }

            if (foundRow == -1) {
                return -1;
            }

            for (int currentPos = foundRow; currentPos > targetRow;
                 --currentPos) {
                swap(rightmostOnePosition[currentPos],
                     rightmostOnePosition[currentPos - 1]);
            }
        }

        return totalSwaps;
    }
};
