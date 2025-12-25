long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        long long res = 0;
        for (int i = 0; i < k; i++) {
            res += (happiness[i] - i <= 0) ? 0 : happiness[i] - i;
        }
        return res;
    }
