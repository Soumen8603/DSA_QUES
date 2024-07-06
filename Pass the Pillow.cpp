int passThePillow(int n, int time) {
        int turn=time/(n-1);
        if(turn%2==0){
            return (time%(n-1))+1;
        }
        else{
            int rem=time%(n-1);
            return n-rem;
        }
    }
