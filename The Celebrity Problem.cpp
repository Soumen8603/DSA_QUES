 int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        
        stack<int>st;
        
        vector<int>cnt(n,0);
        
        for(int i =0;i < n;i++){
        bool check = true;
           for(int j = 0;j < n;j++){
               if(mat[i][j] == 1){
                   check = false;
                   cnt[j]++;
               }
           }
           if(check == true){
               st.push(i);
           }
        }
        
       
        
        while(!st.empty()){
            int val = st.top();
            if(cnt[val] == n-1){
                return val;
            }
            st.pop();
        }
        return -1;
        
    }
