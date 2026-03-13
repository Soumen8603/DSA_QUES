 long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;

        ll left = 1;
        ll right = 1e16;

        auto canCompleteInTime = [&](ll timeLimit) -> bool {
            ll totalHeightReduced = 0;

            for (int& workerTime : workerTimes) {
                totalHeightReduced += static_cast<ll>(
                    sqrt(timeLimit * 2.0 / workerTime + 0.25) - 0.5);
            }

            return totalHeightReduced >= mountainHeight;
        };

        ll firstTrueIndex = -1;

        while (left <= right) {
            ll mid = left + (right - left) / 2;

            if (canCompleteInTime(mid)) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstTrueIndex;
    }
