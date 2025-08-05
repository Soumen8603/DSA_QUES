int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool>check(n,false);
        int count = 0;
        int flag;
        for(int i = 0;i < n;i++){
            flag = 0;
            
            for(int j = 0;j < n;j++){
                if(baskets[j] >= fruits[i] && check[j] == false){
                    check[j] = true;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)count++;
        }
        return count;
    }
