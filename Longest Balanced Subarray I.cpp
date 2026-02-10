 int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int l = 0;l < n-1;l++){
            unordered_set<int>evenSet,oddSet;
            for(int r = l;r < n;r++){
                if(nums[r] % 2 == 0){
                    evenSet.insert(nums[r]);
                }
                else{
                    oddSet.insert(nums[r]);
                }
                 if(oddSet.size() == evenSet.size()){
                ans = max(ans,r-l+1);
            }
            }
           
        }
        return ans;
    }
