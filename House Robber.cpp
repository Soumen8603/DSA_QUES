// Tabulation Method
int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[0] = nums[0];
        if(n == 1){
            return dp[0];
        }
       for(int i = 1;i < n;i++){
        int prevTwo;
        if(i < 2){
            prevTwo = 0;
        }
        else{
            prevTwo = dp[i-2];
        }
        dp[i] = max(dp[i-1],nums[i] + prevTwo);
       }
        return dp[n-1];
    }

// Space Optimization Method

int rob(vector<int>& nums) {
        int n = nums.size();

        int prefix = nums[0];
        if (n == 1) {
            return prefix;
        }
        for (int i = 1; i < n; i++) {
            int prevTwo;
            if (i < 2) {
                prevTwo = 0;
            }
            int temp = prefix;

            prefix = max(prevTwo + nums[i], prefix);
            prevTwo = temp;
        }
        return prefix;
    }
