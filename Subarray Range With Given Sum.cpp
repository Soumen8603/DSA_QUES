 int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        int count = 0,prefix = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i < arr.size();i++){
            prefix += arr[i];
            if(prefix == tar)count++;
            if(mp[prefix - tar] > 0)count += mp[prefix - tar];
            mp[prefix]++;
        }
        
        return count;
}
        
