long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = (long long)(prices[0] * strategy[0]);
        for (int i = 1; i < n; i++) {
            prefixSum[i] =
                (long long)(prefixSum[i - 1] + (prices[i] * strategy[i]));
        }

        long long total = prefixSum[n - 1];

        long long maxi = total;
        long long currentWindowSum = 0;
        for (int j = k / 2; j <= k - 1; j++) {
            currentWindowSum += prices[j];
        }
        for (int i = 0; i <= n - k; i++) {
            long long prevSum = 0;
            if (i == 0) {
                prevSum = prefixSum[k - 1];
            } else {
                prevSum = prefixSum[i + k - 1] - prefixSum[i - 1];
            }
            if (currentWindowSum > prevSum) {
                maxi = max(maxi, total + currentWindowSum - prevSum);
            }

            if (i < n - k) {
                currentWindowSum -= prices[i + (k / 2)];
                currentWindowSum += prices[i + k];
            }
        }
        return maxi;
    }
