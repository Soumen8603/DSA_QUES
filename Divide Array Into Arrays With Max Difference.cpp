vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        if (n % 3 != 0) {
            return {}; // early return if not divisible by 3
        }

        for (int i = 0; i < n; i += 3) {
            // We take 3 consecutive elements starting at index i
            if (nums[i + 2] - nums[i] <= k) {
                res.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                return {}; // return empty if difference exceeds k
            }
        }

        return res;
    }
