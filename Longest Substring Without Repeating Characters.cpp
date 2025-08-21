int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<int, int> mp;
        int n = s.size();
        int ans = 0;
        while (right < n) {
            if (mp.find(s[right]) == mp.end()) {
                mp[s[right]] = right;
                right++;
            } else {
                int index = mp[s[right]] + 1;
                ans = max(ans, right - left);
                while (left < index) {
                    mp.erase(s[left]);
                    left++;
                }
                mp[s[right]] = right;
                right++;
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
