  long long reversedBits(long long x) {
        // code here
        int arr[32];
        for(int i=0;i<32;i++){
            arr[i]=x%2;
            x=x/2;
        }
        long long ans=0;
        for(int i=31;i>=0;i--){
            ans+=(arr[i]*(long long)pow(2,(31-i)));
        }
        return ans;
    }
