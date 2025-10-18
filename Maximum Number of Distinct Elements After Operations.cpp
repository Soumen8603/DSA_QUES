int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());

        long long last_distinct_element = numeric_limits<long long>::min();
        
        int distinct_count = 0;

        for (int num : nums) {
            long long required_new_target = max((long long)num - k, last_distinct_element + 1);
            long long max_possible_val = (long long)num + k;

            if (required_new_target <= max_possible_val) {
                distinct_count++;
                last_distinct_element = required_new_target;
            }
        }
        
        return distinct_count;
    }
