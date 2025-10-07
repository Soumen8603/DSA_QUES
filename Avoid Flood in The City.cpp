 vector<int> avoidFlood(vector<int>& rains) {
         int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full;
        set<int> dryDays;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                int lake = rains[i];
                if (full.count(lake)) {
                    auto it = dryDays.lower_bound(full[lake]);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                full[lake] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
