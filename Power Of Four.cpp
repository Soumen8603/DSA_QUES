bool isPowerOfFour(int n) {
        if(n <= 0)return false;
        if((n & (n-1)) == 0){
            int one_pos = 0;
            while(n % 2 == 0){
               n = n/2;
               one_pos++;
                
            }
            if(one_pos % 2 == 0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
