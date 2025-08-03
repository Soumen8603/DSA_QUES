int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), amount(n);
        for (int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
            amount[i] = fruits[i][1];
        }

        int res = 0;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += amount[right];

            while (left <= right) {
                int distLeft = abs(startPos - pos[left]);
                int distRight = abs(startPos - pos[right]);

                // Two path options to reach both ends
                int steps1 =
                    (startPos <= pos[left])
                        ? pos[right] - startPos
                        : (startPos - pos[left]) + (pos[right] - pos[left]);
                int steps2 =
                    (startPos >= pos[right])
                        ? startPos - pos[left]
                        : (pos[right] - startPos) + (pos[right] - pos[left]);

                if (min(steps1, steps2) <= k)
                    break;

                sum -= amount[left++];
            }

            res = max(res, sum);
        }

        return res;
    }
