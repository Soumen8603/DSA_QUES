 vector<int> getSneakyNumbers(vector<int>& nums) {
       int n = nums.size() - 2;
       vector<int>result;
       for(int i = 0;i < nums.size();i++){
        int val = nums[i] % n;
        nums[val] += n;
       }
       for(int i = 0;i < n;i++){
        int count = nums[i] / n;
        if(count == 2){
            result.push_back(i);
            if(result.size()==2)break;
        }
       }
       return result;
    }
