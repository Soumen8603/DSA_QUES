bool isSubsequence(string s, string t) {
        if(s == "")return true;
        int count = 0;
        for(int i = 0;i < t.size();i++){
            if(t[i] == s[count]){
                count++;
               
            }
             if (count == s.size()) return true;
        }
        return false;
    }
