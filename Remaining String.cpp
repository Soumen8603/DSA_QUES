 string printString(string s, char ch, int count) {
        // Your code goes here
        
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(count>0 && s[i]==ch){
                count--;
            }
            else if(count==0){
                ans+=s[i];
            }
        }
        return ans;
    }
