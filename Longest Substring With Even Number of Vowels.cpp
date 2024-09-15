 int findTheLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int xorv = 0;
        int ans = 0;
        mp[0] = -1;

        for(int i = 0;i < s.length();i++){
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                xorv ^= c;
            }
            if(mp.find(xorv) != mp.end()){
                ans = max(ans,i-mp[xorv]);
            }
            else{
                mp[xorv] = i;
            }
        }
        return ans;
        
    }
