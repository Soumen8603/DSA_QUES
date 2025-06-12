 int maxAdjacentDistance(vector<int>& nums) {
        int maxdiff = INT_MIN;
        for(int i = 1;i < nums.size();i++){
            int diff = abs(nums[i]-nums[i-1]);
            maxdiff = max(diff,maxdiff);
        }
        if(abs(nums[nums.size()-1] - nums[0]) > maxdiff){
            maxdiff =abs(nums[nums.size()-1] - nums[0]);
        }
        return maxdiff;
    }
