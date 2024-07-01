bool isOdd(int n){
        if(n%2!=0){
            return true;
        }
        return false;
    }
    
    bool threeConsecutiveOdds(vector<int>& arr) {
       int n=arr.size();
       int count=0;
       for(int i=0;i<n;i++){
          if(isOdd(arr[i])){
            count++;
            if(count==3){
                return true;
            }
          }
          else{
            count=0;
          }
       }
       return false;
           
    }
