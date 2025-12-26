int bestClosingTime(string customers) {
        int customer = 0;
        int minClosingTime = -1;
        int minPenalty = INT_MAX;
        for(int i = 0;i < customers.size();i++){
            if(customers[i] == 'Y'){
                customer++;
            }
        
        }
        int n = customers.size();
        int noCustomer = 0;
        for(int i = 0;i <= n;i++){
            int currPenalty = customer + noCustomer;
            if(currPenalty < minPenalty){
                minPenalty = currPenalty;
                minClosingTime = i;
            }
            if(customers[i] == 'N'){
                noCustomer++;
            }
            else{
                customer--;
            }
        }
        return minClosingTime;
    }
