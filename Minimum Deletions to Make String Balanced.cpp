int minimumDeletions(string s) {


        int mini = INT_MAX;
        int n = s.size();
        int aCount[n];
        aCount[n-1]=0;
        int bCount[n];
        bCount[0]=0;
        



        for(int i = 1;i < n;i++){
           char prev = s[i-1];

           bCount[i] = bCount[i-1];
           if(prev == 'b'){
            bCount[i]+=1;
           }
        }

        for(int i = n-2;i >= 0;i--){
           char prev = s[i+1];

           aCount[i] = aCount[i+1];
           if(prev == 'a'){
            aCount[i]+=1;
           }
        }

       for(int i=0;i<n;i++){
        mini=min(mini,aCount[i]+bCount[i]);
        
       }
       return mini;

    }
