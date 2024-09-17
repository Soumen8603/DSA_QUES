 int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n==1)return 0;
        sort(arr.begin(),arr.end());
        
        int high = arr[n-1] - k;
        int low = arr[0] + k;
        int res = arr[n-1] - arr[0];
        
        for(int i = 1;i < n;i++){
            int mini = min(low,arr[i]-k);
            int maxi = max(arr[i-1]+k,high);
            if(mini<0)continue;
            
            res = min(res,maxi-mini);
        }
        return res;
    }
