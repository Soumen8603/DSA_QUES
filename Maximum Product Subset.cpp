 long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        
        int mod=1e9+7;
        
        long long pos=0,zerocount=0;
        
        vector<int>neg;
        
        int n = arr.size();
        
        
        if(arr.size() == 1){
            return arr[0];
        }
        
        for(int i = 0;i < n;i++){
            if(arr[i] < 0){
                neg.push_back(arr[i]);
            }
            else if(arr[i] == 0){
                zerocount++;
            }
            
            else{
               if(pos==0){
                   pos=1;
               }
               pos = (pos * arr[i])%mod;
            }
        } 
        
        if(neg.size()>1){
            
            sort(neg.begin(),neg.end());
            
            int m = neg.size();
            
            int end;
            
             if(m % 2 == 0){
                    end=m;
                }
                else{
                    end=m-1;
                }
                
            for(int i = 0;i < end;i++){
                
                if(pos==0){
                    pos=1;
                }
                
                
                pos = (pos * neg[i])%mod;
               
                }
                
                return pos;
                
        }
        
        else if(neg.size()==1 && zerocount >=1 && pos == 0){
            return 0;
        }
        else{
            return pos;
        }
            
    }
