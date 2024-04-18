 vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int>ans;
        for(int i=0;i<n+2;i++){
           int index=abs(arr[i]);
           if(arr[index]>0){
               arr[index]=-arr[index];
           }
           else{
               ans.push_back(index);
           }
        }
        return ans;
        
    }
