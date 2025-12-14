int numberOfWays(string corridor) {
        int seats = 0;
        int n = corridor.size();
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S')
                seats++;
        }
        if (seats == 0 || seats % 2 == 1) {
            return 0;
        }
        if (seats == 2) {
            return 1;
        }

        int seatCount = 0;
        int prev = -1;
        int i = 0;
        for (i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                seatCount++;
                if (seatCount == 2) {
                    prev = i;
                    break;
                }
            }
        }

        seatCount = 0;
        long long ans = 1;
        int mod = 1e9 + 7;
        for (int j = i + 1; j < n; j++) {
            if (corridor[j] == 'S') {
                seatCount++;
                if (seatCount == 1) {
                    ans = (ans * (j - prev)) % mod;
                }
                if (seatCount == 2) {
                    prev = j;
                    seatCount = 0;
                }
            }
        }
        return ans;
    }
