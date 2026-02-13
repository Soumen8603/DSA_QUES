int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            ans = max(ans, j - i);
            i = j;
        }

        vector<pair<char, char>> pairs = {{'a', 'b'}, {'a', 'c'}, {'b', 'c'}};

        for (auto p : pairs) {
            char x = p.first, y = p.second;

            unordered_map<int, int> mp;
            mp[0] = -1;

            int diff = 0;

            for (int i = 0; i < n; i++) {

                if (s[i] != x && s[i] != y) {
                    mp.clear();
                    mp[0] = i;
                    diff = 0;
                    continue;
                }

                if (s[i] == x)
                    diff++;
                else
                    diff--;

                if (mp.count(diff))
                    ans = max(ans, i - mp[diff]);
                else
                    mp[diff] = i;
            }
        }

        unordered_map<string, int> mp;
        mp["0#0"] = -1;

        int a = 0, b = 0, c = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a++;
            else if (s[i] == 'b')
                b++;
            else
                c++;

            string key = to_string(a - b) + "#" + to_string(a - c);

            if (mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        return ans;
    }
