 int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int l = 0;l < n;l++){
            vector<int>freq(26,0);
            unordered_set<char>distinct;
            for(int r = l;r < n;r++){
                distinct.insert(s[r]);
                freq[s[r]-'a']++;
                int max_freq = INT_MIN;
                for(int i = 0;i < 26;i++){
                    max_freq = max(max_freq,freq[i]);
                }
                int distinct_char = distinct.size();
                if(max_freq * distinct_char == r - l + 1){
                    ans = max(ans,r-l+1);
                }
            }
        }
        return ans;
    }
