int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_map<int,int>mp;
        int s = hFences.size();
        for(int i = 0;i < s-1;i++){
            for(int j = i+1;j < s;j++){
                mp[hFences[j] - hFences[i]]++;
            }
        }
        int maxi = INT_MIN;
        s = vFences.size();
        for(int i = 0;i < s-1;i++){
            for(int j = i+1;j < s;j++){
                int dist = vFences[j] - vFences[i];
                if(mp.find(dist) != mp.end()){
                    maxi = max(maxi,dist);
                }
            }
        }
        if(maxi == INT_MIN){
            return -1;
        }
        return (1LL * maxi * maxi) % 1000000007;
    }
