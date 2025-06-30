int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int maxlen = 0;
        for (int i = 0; i < n; i++) {

            if (mp[nums[i] + 1] > 0) {
                maxlen = max(maxlen, (mp[nums[i] + 1] + mp[nums[i]]));
            }
        }
        return maxlen;
    }
