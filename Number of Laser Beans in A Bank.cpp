 int numberOfBeams(vector<string>& bank) {
        int prevSecurity = -1;
        
        int m = bank.size();
        int n = bank[0].size();
        if(m==1)return 0;
        int currDevice = 0;
        int total = 0;
        for(int i = 0;i < m;i++){
            currDevice = 0;
            for(int j = 0;j < n;j++){
                if(bank[i][j] == '1')currDevice+=1;
            }
            if(prevSecurity != -1 && currDevice > 0){
                total += prevSecurity * currDevice;
                prevSecurity = currDevice;
            }
            if(prevSecurity == -1 && currDevice > 0){
                prevSecurity = currDevice;
            }
        }
        return total;
    }
