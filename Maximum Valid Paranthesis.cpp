int maxLength(string str) {
        // code here
        int n = str.length();
        
      
        int open = 0;
        int close = 0,maxi = 0;
        for(int i = 0;i < n;i++){
            if(str[i] == '(')open++;
            else close++;
            
            if(close > open){
                close = 0;
                open = 0;
            }
            if(close == open){
                maxi = max(maxi,open+close);
            }
        }
        
        
        open=close=0;
        for(int i = n-1;i >= 0;i--){
            if(str[i] == '(')open++;
            else close++;
            
            if(close < open){
                close = 0;
                open = 0;
            }
            if(close == open){
                maxi = max(maxi,open+close);
            }
        }
        return maxi;
    }
