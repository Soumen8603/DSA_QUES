double averageWaitingTime(vector<vector<int>>& customers) {
        int customer=customers.size();
        int i=0;
        double time=customers[0][0];
        double wait=0;
        while(i<customer){
            if(time>=customers[i][0]){
            time+=customers[i][1];
            wait+=(time-customers[i][0]);
            }
            else{
                time=customers[i][0];
                time+=customers[i][1];
                wait+=(time-customers[i][0]);
            }
            i++;
        }
        return wait/customer;
    }
