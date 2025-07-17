int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int profit = sell - buy;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
                sell = prices[i];
            } else if (prices[i] > sell) {
                sell = prices[i];
            }
            profit = max(profit, sell - buy);
        }
        return profit;
    }
