// Tabulation
long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n,0);
        dp[0] = 1;
        long long sum = 1;
        for(int i = 1;i < n;i++){
            if(prices[i] == prices[i-1]-1){
                dp[i] = dp[i-1]+1;
            }
            else{
                dp[i] = 1;
            }
            sum += dp[i];
        }
        return sum;
        
    }

// Space optimization
long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        
        long long prev = 1;
        long long sum = 1;
        long long curr = 0;
        for(int i = 1;i < n;i++){
            if(prices[i] == prices[i-1]-1){
                curr = prev + 1;
                
            }
            else{
                curr = 1;
            }
            sum += curr;
            prev = curr;
        }
        return sum;
        
    }
