long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<long long> closed(k + 1, 0);
        vector<long long> long_pos(k + 1, -1e15); 
        vector<long long> short_pos(k + 1, -1e15); 

        for (int p : prices) {
            vector<long long> next_closed = closed;
            vector<long long> next_long = long_pos;
            vector<long long> next_short = short_pos;

            for (int j = 1; j <= k; ++j) {
                next_long[j] = max(long_pos[j], closed[j-1] - p);
                next_short[j] = max(short_pos[j], closed[j-1] + p);
                next_closed[j] = max(next_closed[j], long_pos[j] + p);
                next_closed[j] = max(next_closed[j], short_pos[j] - p);
            }

            closed = next_closed;
            long_pos = next_long;
            short_pos = next_short;
        }

        return closed[k];
    }
