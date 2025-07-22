int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefix[i] = sum;
        }
        map<int, int> mp;
        int start = 0;
        int ans = nums[0];
        sum = 0;
        mp[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && mp[nums[i]] >= start) {
                start = mp[nums[i]] + 1;
            }
            mp[nums[i]] = i;

            if (start == 0) {
                sum = prefix[i];
            } else {
                sum = prefix[i] - prefix[start - 1];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
