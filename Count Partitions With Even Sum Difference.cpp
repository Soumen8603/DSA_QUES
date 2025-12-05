int countPartitions(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        int count = 0;
        int prevSum = 0;
        for(int i = 0;i < n-1;i++){
            prevSum += nums[i];
            if(prevSum % 2 == 0 && (sum - prevSum) % 2 == 0){
                count++;
            }
            else if(prevSum % 2 != 0 && (sum - prevSum) % 2 != 0){
                count++;
            }
        }
        return count;
    }
