int countSubsequences(const string& s,const string& next){
        int i = 0;
        int j = 0;
        int count = 0;
        int m = next.size();
        while(i < s.size()){
            if(s[i] == next[j]){
                j++;
                if(j==m){
                    j=0;
                    count++;
                }
            }
            i++;
        }
        return count;
    }
string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int>freq(26);
        for(int i = 0;i < n;i++){
            freq[s[i]-'a']++;
        }
        string curr="";
        queue<string>q;
        q.push(curr);
        string res;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            string next = curr;
            for(char c = 'a';c <= 'z';++c){
                if(freq[c-'a']<k){
                    continue;
                }
                next.push_back(c);
                if(countSubsequences(s,next)>=k){
                    res = next;
                    q.push(next);
                }
                next.pop_back();
            }
        }
        return res;
        

    }
