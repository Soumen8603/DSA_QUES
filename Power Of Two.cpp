 bool isPowerOfTwo(int n) {
        if(n == 1)return true;
       if(n > 1){
        if((n & (n-1)) == 0){
            return true;
        }
        else{
            return false;
        }
       }
       return false;
    }
