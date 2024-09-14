 int longestSubarray(vector<int>& nums) {
        int maxi = nums[0];
        for(int i =1;i < nums.size();i++){
           maxi = max(maxi,nums[i]);
        }
         int maxSize = 0;
         int n = nums.size();
        for(int i = 0;i < n;i++){
             if(nums[i] == maxi){
                int size = 0;
                while((i < n) && (nums[i]==maxi)){
                    size++;
                    i++;
                }
                maxSize = max(size,maxSize);
             }
        }

        return maxSize;
    }
