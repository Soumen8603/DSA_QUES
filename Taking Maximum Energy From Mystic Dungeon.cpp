 int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>vis(n,0);
        int maxi = INT_MIN;
        for(int i = 0;i < n;i++){
            if(vis[i])continue;
            int sum = 0;
            int j = i;
            while(j < n){
                vis[j] = 1;
                sum += energy[j];
                sum = max(sum,energy[j]);
                j += k;
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
