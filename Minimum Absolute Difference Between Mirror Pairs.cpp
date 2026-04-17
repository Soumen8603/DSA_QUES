class Solution {
private:
    int reverseDigit(int num){
        int ans = 0;
        while(num > 0){
            int digit = num % 10;
            ans = ans * 10 + digit;
            num = num / 10;
        }
        return ans;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = INT_MAX;
        for(int i = 0;i < nums.size();i++){
            if(mp.count(nums[i])){
                ans = min(ans,abs(mp[nums[i]] - i));
            }

            int reversenum = reverseDigit(nums[i]);
            mp[reversenum] = i;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
