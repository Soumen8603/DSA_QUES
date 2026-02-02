 int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], currentMax = 0;
        int minSum = nums[0], currentMin = 0;
        
        for (int x : nums) {
            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);
            
            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);
            
            totalSum += x;
        }
        
        return (maxSum < 0) ? maxSum : max(maxSum, totalSum - minSum);
    }
