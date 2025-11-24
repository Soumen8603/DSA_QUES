vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr = 0;
        int n = nums.size();
        vector<bool>ans(n,false);
        for(int i = 0; i < n;i++){
            curr = ((curr << 1) + nums[i]) % 5;
            if(curr == 0){
                ans[i] = true;
            }
        }
        return ans;
    }
