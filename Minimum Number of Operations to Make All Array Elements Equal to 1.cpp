class Solution {
    private:
    int findGCD(int a,int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int findMinLength(vector<int>&nums){
        int n = nums.size();
       
        int minlength = n;
        for(int i = 0;i < n;i++){
            int currentGCD = 0;
            for(int j = i;j < n;j++){
                currentGCD = findGCD(currentGCD,nums[j]);
                if(currentGCD == 1){
                    minlength = min(minlength,j-i+1);
                    break;
                }
            }
        }
        return minlength;

    }
public:
    int minOperations(vector<int>& nums) {
        int gcdVal = 0;
        vector<int>ones;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i]==1){
                ones.push_back(i);
            }
            gcdVal = findGCD(gcdVal,nums[i]);
        }
        if(gcdVal != 1){
            return -1;
        }
        if(ones.size() >= 1){
            return n - ones.size();
        }
        int minLength = findMinLength(nums);
        if(minLength == 2){
            return n;
        }
        else{
            return n + (minLength - 2);
        }
    }
};
