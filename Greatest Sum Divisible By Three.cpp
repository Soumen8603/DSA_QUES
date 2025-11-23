int maxSumDivThree(vector<int>& nums) {
         vector<int> dp = {0, (int)-1e9, (int)-1e9};

        for (int num : nums) {
            vector<int> next_dp = dp;
            
            for (int i = 0; i < 3; i++) {
                if (dp[i] != -1e9) {
                    int current_sum = dp[i] + num;
                    int remainder = current_sum % 3;
                    next_dp[remainder] = max(next_dp[remainder], current_sum);
                }
            }
            dp = next_dp;
        }

        return dp[0];
    }
