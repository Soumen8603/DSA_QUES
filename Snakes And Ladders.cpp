 int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        queue<int> q;
        q.push(1);

        vector<int> dist(target + 1, -1);
        dist[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 1; i <= 6; i++) {
                int next = curr + i;

                if (next > target)
                    break;

                int r_from_bottom = (next - 1) / n;
                int r = n - 1 - r_from_bottom;
                int c = (next - 1) % n;

                if (r_from_bottom % 2 != 0) {
                    c = n - 1 - c;
                }

                int destination = (board[r][c] != -1) ? board[r][c] : next;

                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;

                    if (destination == target) {
                        return dist[destination];
                    }

                    q.push(destination);
                }
            }
        }

        return -1;
    }
