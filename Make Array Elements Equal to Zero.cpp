int countValidSelections(vector<int>& nums) {
       
        int n = nums.size();
        vector<int>prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i = 1;i < n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int count = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0){
                int leftSum = prefixSum[i] - nums[i];
                int rightSum = prefixSum[n-1] - prefixSum[i];
                if(leftSum == rightSum)count += 2;
                else if (abs(leftSum - rightSum) == 1)count += 1;
            }
        }
        return count;
    }
