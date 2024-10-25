 vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,int>mp;
        vector<string>ans;
        int n = folder.size();
        sort(folder.begin(),folder.begin()+n);
        for(int i = 0;i < n;i++){
            string str = folder[i];
            stringstream ss(str);
            string token;
            char delimiter = '/';
            
            string check = "";
            bool checki = true;
            
            while (getline(ss,token,delimiter)) {
                check += '/';
                check += token;
                if(mp[check] > 0){
                    
                    checki = false;
                    break;

                }
                
            }
            if(checki == true){
                mp[check]++;
                ans.push_back(str);
            }
        }

        return ans;
    }
