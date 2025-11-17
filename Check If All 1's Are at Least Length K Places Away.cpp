 bool kLengthApart(vector<int>& nums, int k) {
        int lastOne = -1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 1 && lastOne == -1){
                lastOne = i;
            }
            else if(nums[i] == 1 && lastOne != -1){
                int dist = (i - lastOne) - 1;
                if(dist < k){
                    return false;
                }
                lastOne = i;
               
            }
        }
        return true;
    }
