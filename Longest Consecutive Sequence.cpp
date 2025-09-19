int longestConsecutive(vector<int>& nums) {
       if (nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        

        int best = 0;
        for (int x : s) {
            if (s.count(x-1)) continue;

            int cur = x;
            int len = 1;
            while (s.find(cur + 1) != s.end()) {
                ++cur;
                ++len;
            }
            if (len > best) best = len;
        }
        return best;
    }
