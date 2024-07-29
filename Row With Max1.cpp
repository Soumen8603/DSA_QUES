int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int rowIndex;
        int maxOne=0;
        for(int i = 0;i < n;i++){
            int num=0;
            for(int j = m-1;j >= 0;j--){
                if(arr[i][j] == 1){
                    num++;
                }
                else{
                    break;
                }
            }
            if(num > maxOne){
                rowIndex = i;
                maxOne=num;
            }
        }
        
        if(maxOne == 0){
            return -1;
        }
        else{
            return rowIndex;
        }
    }
