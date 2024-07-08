 int findTheWinner(int n, int k) {
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        int index=0;
        while(v.size()!=1){
          index=(index+(k-1))%v.size();
          v.erase(v.begin()+index);
        }
        return v[0];
    }
