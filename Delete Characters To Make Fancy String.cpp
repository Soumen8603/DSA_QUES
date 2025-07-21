 string makeFancyString(string s) {
        string ans = "";
        int i;
        int n = s.size();
        if (n < 3)
            return s;
        for (i = 0; i < n - 2; i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
                continue;

            ans += s[i];
        }
        ans += s[n - 2];
        ans += s[n - 1];

        return ans;
    }
