int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int i = 0;
        int j = 0;
        int max_window = 0;
        sort(nums.begin(), nums.end());
        while (j < n) {

            while (i <= j && (long long)nums[j] > (long long)k * nums[i]) {
                i++;
            }

            max_window = max(max_window, j - i + 1);
            j++;
        }
        return n - max_window;
    }
