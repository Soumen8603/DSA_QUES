int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
            int total=0;
            int closesum=INT_MAX;
            
            int n=arr.size();
            for(int i=0;i<n;i++){
                int second=i+1;
                int third=n-1;
                while(second<third){
                    int currentsum=arr[i]+arr[second]+arr[third];
                    if(currentsum<target){
                        if(target-currentsum<closesum){
                            closesum=target-currentsum;
                            total=currentsum;
                        }
                        second++;
                    }
                    else{
                        if(currentsum-target<=closesum){
                            closesum=currentsum-target;
                            total=currentsum;
                        }
                        third--;
                    }
                }
            }
           
                
         return total;   
            
    }    
