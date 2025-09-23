int compareVersion(string version1, string version2) {
        vector<int>token1;
        vector<int>token2;
        char delimiter = '.';
        stringstream ss1(version1);
        stringstream ss2(version2);
        string tok1,tok2;
        while(getline(ss1,tok1,delimiter)){
            int num = stoi(tok1);
            token1.push_back(num);
        }
        while(getline(ss2,tok2,delimiter)){
            int num = stoi(tok2);
            token2.push_back(num);
        }

        int m = token1.size(),n = token2.size();
        int len = min(m,n);
        int i = 0;
        while(i < len){
            if(token1[i] > token2[i]){
                return 1;
            }
            else if(token1[i] < token2[i]){
                return -1;
            }
            i++;
        }
        if(i < m){
            while(i < m){
                if(token1[i] > 0)return 1;
                i++;
            }
        }
        if(i < n){

            while(i < n){
                if(token2[i] > 0)return -1;
                i++;
            }
        }
        return 0;
    }
