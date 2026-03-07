 int minFlips(string s) {
        int n = s.size();
        string doubleS = s + s;

        int diff1 = 0;
        int diff2 = 0;
        int min_flips = INT_MAX;

        for (int i = 0; i < 2 * n; ++i) {
            if (doubleS[i] != (i % 2 == 0 ? '0' : '1')) {
                diff1++;
            }
            if (doubleS[i] != (i % 2 == 0 ? '1' : '0')) {
                diff2++;
            }

            if (i >= n) {
                int left = i - n;
                if (doubleS[left] != (left % 2 == 0 ? '0' : '1')) {
                    diff1--;
                }
                if (doubleS[left] != (left % 2 == 0 ? '1' : '0')) {
                    diff2--;
                }
            }

            if (i >= n - 1) {
                min_flips = min({min_flips, diff1, diff2});
            }
        }

        return min_flips;
    }
