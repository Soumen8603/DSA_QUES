int numOfWays(int n) {
        long long mod = 1e9 + 7;
        
        
        long long aba = 6; 
        long long abc = 6;
        
        for (int i = 2; i <= n; ++i) {
            long long prev_aba = aba;
            long long prev_abc = abc;
            
            
            aba = (3 * prev_aba + 2 * prev_abc) % mod;
            abc = (2 * prev_aba + 2 * prev_abc) % mod;
        }
        
        return (aba + abc) % mod;
    }
