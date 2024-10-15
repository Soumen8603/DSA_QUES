long long minimumSteps(string s) {
        long long zerocount = 0;
        long long count = 0;
        int n = s.size();
        for(int i = n;i >= 0;i--){
            if(s[i] == '0')zerocount++;
            if(s[i] == '1')count+=zerocount;
        }
        return count;
    }
