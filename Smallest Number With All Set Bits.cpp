int smallestNumber(int n) {
        int powVal;
        for(int i = 0;i <= 10;i++){
            if(pow(2,i) > n){
                powVal = i;
                break;
            }
        }
        return (pow(2,powVal)-1);
    }
