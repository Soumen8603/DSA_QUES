int maxIncreasingSubarrays(vector<int>& nums) {
        int maxLength = 0;
        int previousLength = 0;
        int currentLength = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            ++currentLength;

            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                maxLength = max({maxLength, currentLength / 2,
                                 min(previousLength, currentLength)});
                previousLength = currentLength;
                currentLength = 0;
            }
        }

        return maxLength;
    }
