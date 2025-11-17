int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1);

        dp[0] = 0;

        if (n >= 1) {
            dp[1] = dp[0] + costs[0] + 1;
        }

        if (n >= 2) {
            long long path02 = dp[0] + costs[1] + 4;
            long long path12 = dp[1] + costs[1] + 1;
            dp[2] = min(path02, path12);
        }

        if (n >= 3) {
            long long path03 = dp[0] + costs[2] + 9;
            long long path13 = dp[1] + costs[2] + 4;
            long long path23 = dp[2] + costs[2] + 1;
            dp[3] = min({path03, path13, path23});
        }
        
        for (int i = 4; i <= n; i++) {
            long long val = costs[i - 1]; 
            
            long long jump1 = dp[i - 1] + 1 + val;
            long long jump2 = dp[i - 2] + 4 + val;
            long long jump3 = dp[i - 3] + 9 + val;
            
            dp[i] = min({jump1, jump2, jump3});
        }

        return (int)dp[n];
    }
