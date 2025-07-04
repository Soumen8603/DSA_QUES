char kthCharacter(long long k, vector<int>& operations) {
        int count = 0;
        ll val = k;
        while(val > 1){
            int jump = ceil(log2(val));
            val -= pow(2,jump-1);
            count += operations[jump-1];
        }
        return char('a'+(count % 26));
    }
