long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = -1e18;
        long long prefix = 0;
        int n = nums.size();
        vector<long long>minPrefix(k,1e18);
        minPrefix[k-1] = 0;
        for(int i = 0;i < n;i++){
            prefix += nums[i];
            int rem = i % k;
            if(i >= k - 1){
                ans = max(ans,prefix - minPrefix[rem]);
            }
            if(i == k-1){
                ans = prefix;
            }
            minPrefix[rem] = min(minPrefix[rem],prefix);
        }
        return ans;

    }
