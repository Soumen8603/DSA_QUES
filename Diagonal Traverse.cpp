vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        bool goingUp = true; // true: up-right, false: down-left
        int row = 0, col = 0;

        while (ans.size() < m * n) {
            ans.push_back(mat[row][col]);

            if (goingUp) {
                if (col == n - 1) { // hit last column
                    row++;
                    goingUp = false;
                } else if (row == 0) { // hit first row
                    col++;
                    goingUp = false;
                } else { // move up-right
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) { // hit last row
                    col++;
                    goingUp = true;
                } else if (col == 0) { // hit first column
                    row++;
                    goingUp = true;
                } else { // move down-left
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
