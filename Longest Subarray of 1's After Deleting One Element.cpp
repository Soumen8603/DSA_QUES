int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeros = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeros++;

            // shrink window if more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // length is (right - left) because we must delete one element
            ans = max(ans, right - left);
        }

        return ans;
    }
