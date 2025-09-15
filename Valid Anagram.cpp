bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;
        unordered_map<char,int>mp;
        for(int i = 0;i < s.size();i++){
            mp[s[i]]++;
        }
        for(int i = 0;i < t.size();i++){
            if(mp[t[i]] > 0){
                mp[t[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
