vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int,vector<int>>mp;
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(int i = 0;i < queries.size();i++){
            int targ_idx = queries[i];
            int ele = nums[targ_idx];
            const vector<int>&v = mp[ele];
            if(v.size() == 1){
                ans.push_back(-1);
                continue;
            }
            auto it = lower_bound(v.begin(),v.end(),targ_idx);
            int pos = distance(v.begin(),it);
            int m = v.size();
            int left_neighbor = v[(pos-1+m) % m];
            int right_neighbor = v[(pos+1) % m];
            auto get_dist = [&](int j){
                int linear_dist = abs(targ_idx - j);
                return min(linear_dist, n - linear_dist);
            };
            ans.push_back(min(get_dist(left_neighbor), get_dist(right_neighbor)));
        }
        return ans;
    }
