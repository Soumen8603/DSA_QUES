int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxi = INT_MIN;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] <= mini){
                mini = nums[i];
            }
            else{
                maxi = max(maxi,nums[i]-mini);
            }
        }
        if(maxi == INT_MIN){
            return -1;
        }
        else{
            return maxi;
        }
    }
