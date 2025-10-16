int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>remainders;
        for(int num : nums){
            int rem = (num % value + value) % value;
            remainders[rem]++; 
        }
        int mex = 0;
        int res;
        while(true){
            int r = mex % value;
            if(remainders[r] > 0){
                remainders[r]--;
                mex++;
            }
            else{
                return mex;
            }
        }
    }
