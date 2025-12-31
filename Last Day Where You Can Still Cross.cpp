class Solution {
private:
    bool possible(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                q.push({0, i});
                visited[0][i] = true;
            }
        }

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

           
            if (r == row - 1) return true;

            for (int i = 0; i < 4; ++i) {
                int nextR = r + dRow[i];
                int nextC = c + dCol[i];

                if (nextR >= 0 && nextR < row && nextC >= 0 && nextC < col &&
                    grid[nextR][nextC] == 0 && !visited[nextR][nextC]) {
                    visited[nextR][nextC] = true;
                    q.push({nextR, nextC});
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size();
        int ans = 0;

       
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid, row, col, cells)) {
                ans = mid;     
                left = mid + 1;
            } else {
                right = mid - 1; 
            }
        }
        return ans;
    }
};
