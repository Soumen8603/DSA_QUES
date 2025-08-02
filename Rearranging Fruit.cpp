long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        // Count net frequency difference
        for (int x : basket1)
            freq[x]++;
        for (int x : basket2)
            freq[x]--;

        vector<int> toSwap;
        int globalMin = INT_MAX;

        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0)
                return -1; // Not possible
            int times = abs(count) / 2;
            for (int i = 0; i < times; ++i)
                toSwap.push_back(fruit);
            globalMin = min(globalMin, fruit);
        }

        sort(toSwap.begin(), toSwap.end());

        long long cost = 0;
        int n = toSwap.size() / 2; // Only need to swap half

        for (int i = 0; i < n; ++i) {
            cost += min(toSwap[i], 2 * globalMin);
        }

        return cost;
    }
