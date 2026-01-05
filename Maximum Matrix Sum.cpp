 long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        long long positive = 0;
        long long negative = 0;
        int minValue = INT_MAX;
        int negativeCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > 0) {
                    positive += matrix[i][j];
                } else {
                    negative += abs(matrix[i][j]);
                    negativeCount++;
                }
                minValue = min(minValue, abs(matrix[i][j]));
            }
        }

        if (negativeCount % 2 == 0) {
            sum = positive + negative;
        } else {
            sum = positive + negative - 2 * minValue;
        }
        return sum;
    }
