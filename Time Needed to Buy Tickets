int timeRequiredToBuy(vector<int>& tickets, int k) {
       int countsec=0;
       for(int i=0;i<tickets.size();i++){
        if(i<k){
            if(tickets[i]<=tickets[k]){
                countsec+=tickets[i];
            }
            else{
                countsec+=tickets[k];
            }
        }
        else if(i==k){
            countsec+=tickets[k];
        }
        else{
            if(tickets[i]<tickets[k]){
                countsec+=tickets[i];
            }
            else{
                countsec+=tickets[k]-1;
            }
        }
       }
       return countsec;
   }
