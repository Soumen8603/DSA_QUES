vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i : nums){
            if(i % 2 == 0){
                ans.push_back(-1);
                continue;
            }
            bool flag = false;
            for(int j = 1;j <= i-1;j++){
                if((j | (j+1)) == i){
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }
            if(flag == false)ans.push_back(-1);
        }
        return ans;
    }
