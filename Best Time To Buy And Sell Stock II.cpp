int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>profit(n,0);
        for(int i = n-1;i >= 1;i--){
            if(prices[i] - prices[i-1] > 0){
                profit[i] = prices[i] - prices[i-1];
            }
        }
        int maxi = 0;
        for(int i = 0;i < n-1;i++){
            if(profit[i+1] > 0){
                maxi += profit[i+1];
            }
        }
        return maxi;
    }
