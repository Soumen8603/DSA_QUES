 int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        function<int(int, int)> calculateMinScore = [&](int i, int j) -> int {
            if (i + 1 == j) {
                return 0;
            }

            if (dp[i][j] != 0) {
                return dp[i][j];
            }

            int minScore = INT_MAX;

            for (int k = i + 1; k < j; ++k) {
                int currentScore = calculateMinScore(i, k) +
                                   calculateMinScore(k, j) +
                                   values[i] * values[k] * values[j];
                minScore = min(minScore, currentScore);
            }

            dp[i][j] = minScore;
            return minScore;
        };

        return calculateMinScore(0, n - 1);
    }
