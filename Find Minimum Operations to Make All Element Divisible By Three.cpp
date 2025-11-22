int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] % 3 != 0){
                int rem = nums[i] % 3;
                count += min(rem,(3-rem));
            }
        }
        return count;
    }
