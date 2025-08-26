 int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiagSq = LLONG_MIN;
        int ans = 0;

        for (auto& d : dimensions) {
            long long diagSq = 1LL * d[0] * d[0] + 1LL * d[1] * d[1];
            int area = d[0] * d[1];

            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                ans = area;
            } else if (diagSq == maxDiagSq) {
                ans = max(ans, area);
            }
        }
        return ans;
    }
