int maxOperations(string s) {
        int ones = 0;
        int n = s.size();
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                ans += ones;
                int j = i;
                while(s[j] != '1' && j < n){
                    j++;
                }
                i = j-1;
            }
        }
        return ans;
    }
