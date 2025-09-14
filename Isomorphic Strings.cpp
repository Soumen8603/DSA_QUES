  bool isIsomorphic(string s, string t) {
        vector<bool> check(256, false);
        unordered_map<char,char>mp;
        for(int i = 0;i < s.size();i++){
            if(mp.find(s[i]) == mp.end()){
                if(!check[(unsigned char)t[i]]){
                    mp[s[i]] = t[i];
                    check[(unsigned char)t[i]] = true;
                }
                else{
                    return false;
                }
            }
            else{
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
