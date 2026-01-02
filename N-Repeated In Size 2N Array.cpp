int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans;
        for(int i = 0;i < nums.size();i++){
            if(mp[nums[i]] == 1){
                ans = nums[i];
                break;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
