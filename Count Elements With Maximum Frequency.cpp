int maxFrequencyElements(vector<int>& nums) {
        int maxifreq = INT_MIN;
        int elements = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > maxifreq){
                maxifreq = mp[nums[i]];
                elements = 1;
            }
            else if(mp[nums[i]] == maxifreq){
                elements++;
            }
        }
        return maxifreq * elements;
    }
