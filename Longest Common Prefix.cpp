 string longestCommonPrefix(vector<string> arr) {
       
        // your code here
        int n=arr.size();
        
        
        int m=arr[0].size();
        string ans="";
        
        for(int i = 0; i < m; i++){
           char ch = arr[0][i];
           bool match = true;
           for(int j = 0; j < n; j++){
               if(arr[j].size() < i || arr[j][i]!=ch){
                   match=false;
                   break;
               }
           }
           if(match==false){
               break;
           }
           else{
               ans+=ch;
           }
           
        }
        if(ans.size()==0){
            ans+="-1";
        }
        return ans;
    }
