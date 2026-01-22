int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (true) {
            bool isSorted = true;
            for (int i = 0; i < (int)nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    isSorted = false;
                    break;
                }
            }

            if (isSorted)
                return operations;

            long long minSum = LLONG_MAX;
            int targetIndex = -1;

            for (int i = 0; i < (int)nums.size() - 1; i++) {
                long long currentSum = (long long)nums[i] + nums[i + 1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    targetIndex = i;
                }
            }

            nums[targetIndex] = (int)minSum;
            nums.erase(nums.begin() + targetIndex + 1);
            operations++;
        }
    }
