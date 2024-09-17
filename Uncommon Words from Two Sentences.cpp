 vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
      
        map<string,int>mp;
       
      
        
        stringstream ss(s1);
        string token;
        char delimiter = ' ';
        while(getline(ss,token,delimiter)){
            mp[token]++;
        }
         stringstream ss2(s2);
         string token2;
         while(getline(ss2,token2,delimiter)){
            mp[token2]++;
        }
       for (auto i : mp){
        if(i.second == 1){
            ans.push_back(i.first);
        }
       }
       return ans;
        


    }
