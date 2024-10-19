char recur(int len,int k){
        if(len == 1){
            return '0';
        }
        int half = len/2;
        int middle = half+1;
        if(k == middle)return '1';
        else if(k < middle){
            return recur(half,k);
        }
        else{
            char ans = recur(half,1 + len - k);
            return (ans=='0')?'1':'0';
        }
    }
    char findKthBit(int n, int k) {
        int len = pow(2,n) - 1;
        return recur(len,k);
    }
