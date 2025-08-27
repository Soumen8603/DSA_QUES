 string minWindow(string s, string t) {
        unordered_map<char, int> countT;
        unordered_map<char, int> window;
        for (int i = 0; i < t.size(); i++) {
            countT[t[i]]++;
        }
        int left = 0, right = 0;
        int have = 0, need = countT.size();
        int res[2];
        int resLen = INT_MAX;
        while (right < s.size()) {
            window[s[right]]++;
            if (countT.find(s[right]) != countT.end()) {
                if (window[s[right]] == countT[s[right]]) {
                    have++;
                }
            }
            while (have == need) {
                // update result if smaller window found
                if ((right - left + 1) < resLen) {
                    resLen = right - left + 1;
                    res[0] = left;
                    res[1] = right;
                }

                
                window[s[left]]--;
                if (countT.find(s[left]) != countT.end() &&
                    window[s[left]] < countT[s[left]]) {
                    have--;
                }
                left++;
            }
            right++;
        }

        string ans = "";
        if (resLen != INT_MAX) {
            for (int i = res[0]; i <= res[1]; i++) {
                ans += s[i];
            }
            return ans;
        }
        return ans;
    }
