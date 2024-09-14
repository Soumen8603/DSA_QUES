void rearrange(vector<int> &arr) {
        // code here
        vector<int>neg;
         vector<int>pos;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] < 0){
                neg.push_back(arr[i]);
                
            }
            else{
               pos.push_back(arr[i]); 
            }
        }
        int negI = 0;
        int posI = 0;
        int n = arr.size();
        int i = 0;
        while(i < n && posI < pos.size() && negI < neg.size()){
            if(i % 2==0){
                arr[i] = pos[posI];
                posI++;
            }
            else{
                arr[i] = neg[negI];
                negI++;
            }
            i++;
        }
        
        while(posI < pos.size()){
            arr[i] = pos[posI];
            i++;
            posI++;
        }
        
        while(negI < neg.size()){
            arr[i] = neg[negI];
            i++;
            negI++;
        }
        
    }
