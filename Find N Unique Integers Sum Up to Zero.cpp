vector<int> sumZero(int n) {
        vector<int>ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        int half = n / 2;
        for(int i = half;i > 0;i--){
            ans.push_back(-i);
        }
        if(n % 2 == 1){
            ans.push_back(0);
        }
        for(int i = 1;i <= half;i++){
            ans.push_back(i);
        }
        return ans;
    }
