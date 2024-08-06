static bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}

    int minimumPushes(string word) {
        int unique = 0;

        map<char,int>mp;

        for(int i = 0;i < word.size();i++){
            if(mp.count(word[i]) == 0){

               unique++;
            }
            mp[word[i]]++;
        }

        if(unique <= 8)return word.size();

        vector<pair<char,int>>v;
        copy(mp.begin(),
       mp.end(),
       back_inserter<vector<pair<char, int> > >(v));

       sort(v.begin(),v.end(),myComparison);


       int i = 0;
       int ans = 0;
       int multiplier = 1;
       int count = 8;
       while(i < v.size()){
       
        ans += (v[i].second * multiplier);
        i++;
        count--;
        
        if(count == 0){
            multiplier++;
            count = 8;
        }
       }
       return ans;
    }
