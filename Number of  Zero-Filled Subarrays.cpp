long long zeroFilledSubarray(vector<int>& nums) {
        bool check = false;
        long long count = 0;
        long long res = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0 && check == false){
                count++;
                check = true;
            }
            else if(nums[i] == 0 && check == true){
                count++;
            }
            else if(nums[i] != 0 && check == true){
                res += (count*(count + 1)) / 2;
                count = 0;
                check = false;
            }
        }
        if(count > 0){
            res += (count*(count + 1)) / 2;
        }
        return res;
    }
