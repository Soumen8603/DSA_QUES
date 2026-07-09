 vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int group_id = 1;
        unordered_map<int,int>mp;
        mp[0] = group_id;
        for(int i = 1;i < n;i++){
            if(nums[i] - nums[i-1] > maxDiff){
                group_id++;
            }
            mp[i] = group_id;
        }
        vector<bool>ans;

        for(int i = 0;i < queries.size();i++){
            int s = queries[i][0], e = queries[i][1];
            if(mp[s] == mp[e]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
