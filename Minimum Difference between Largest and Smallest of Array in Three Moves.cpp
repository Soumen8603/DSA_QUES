int minDifference(vector<int>& nums) {
       if(nums.size()<=4){
        return 0;
       }
       sort(nums.begin(),nums.end());
       int mini=INT_MAX;
       int n=nums.size();
       //case1
      mini=min(mini,nums[n-4]-nums[0]);
      //case2
      mini=min(mini,nums[n-3]-nums[1]);
      //case3
      mini=min(mini,nums[n-2]-nums[2]);
      //case4
      mini=min(mini,nums[n-1]-nums[3]);

      return mini;
    }
