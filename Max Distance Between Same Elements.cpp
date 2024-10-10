 int maxDistance(vector<int> &arr) {
        // Code here
        map<int,int>mp;
        int maxi = INT_MIN;
        for(int i = 0;i < arr.size();i++){
            if(mp[arr[i]] > 0){
                maxi = max(maxi,((i+1) - mp[arr[i]]));
            }
            else{
                mp[arr[i]] = i+1;
            }
        }
        return maxi;
    }
