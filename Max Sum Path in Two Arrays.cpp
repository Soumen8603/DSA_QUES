int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int m = arr1.size(),n = arr2.size();
       
        int sum1 = 0,sum2 = 0;
        int i=0,j=0;
       
       while(i < m && j < n){
           if(arr1[i]<arr2[j]){
               
            sum1 += arr1[i];
            
            i++;
           }
           
            else if(arr1[i] > arr2[j]){
                
            sum2 += arr2[j]; 
            
            j++;
            }
            
            else if(arr1[i] == arr2[j]){
                sum1+=arr1[i];
                sum2+=arr2[j];
                int sum = max(sum1,sum2);
                sum1=sum;
                sum2=sum;
                i++;
                j++;
            }
        }
        
        while(i < m){
            sum1 += arr1[i];
            i++;
        }
        
        while(j < n){
            sum2 += arr2[j];
            j++;
        }
        
        return max(sum1,sum2);
            
            
    }
