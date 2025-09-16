vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>duplicates;
        unordered_map<int,int>mp;
        for(int i = 0;i < nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
               duplicates[nums[i]]++;
            }
            mp[nums[i]] = i;

        }
        vector<int>ans;
        for(int i = 0;i < nums.size();i++){
            int required = target - nums[i];
            if(required == nums[i]){
                if(duplicates[nums[i]] > 0){
                    ans.push_back(i);
                    ans.push_back(mp[nums[i]]);
                    break;
                }
            }
            else if(mp.find(required) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[required]);
                break;
            }
        }
        return ans;
      
    }
