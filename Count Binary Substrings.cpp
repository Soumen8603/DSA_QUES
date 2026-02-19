 int countBinarySubstrings(string s) {
        if (s.length() == 1)
            return 0;
        vector<int> groups;
        char prev = s[0];
        int currLen = 1;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i] == prev) {
                currLen++;
            } else {
                groups.push_back(currLen);
                prev = s[i];
                currLen = 1;
            }
        }
        groups.push_back(currLen);

        n = groups.size();
        if(n == 1)return 0;
        int ans = 0;
        for(int i = 1;i < n;i++){
            ans += min(groups[i],groups[i-1]);
        }
        return ans;
    }
