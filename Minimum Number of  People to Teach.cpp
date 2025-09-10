 int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
         int m = languages.size();

        // Convert each user's languages into an unordered_set for fast lookup
        vector<unordered_set<int>> langSet(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                langSet[i].insert(lang);
            }
        }

        // Step 1: find users in conflict
        unordered_set<int> conflictUsers;
        for (auto &fr : friendships) {
            int u = fr[0] - 1;
            int v = fr[1] - 1;

            bool canTalk = false;
            for (int lang : langSet[u]) {
                if (langSet[v].count(lang)) { // common language exists
                    canTalk = true;
                    break;
                }
            }

            if (!canTalk) {
                conflictUsers.insert(u);
                conflictUsers.insert(v);
            }
        }

        // If no conflicts, no teaching needed
        if (conflictUsers.empty()) return 0;

        // Step 2: count frequency of languages among conflict users
        unordered_map<int, int> langFreq;
        for (int user : conflictUsers) {
            for (int lang : langSet[user]) {
                langFreq[lang]++;
            }
        }

        // Step 3: find language that covers most conflict users
        int maxCover = 0;
        for (auto &p : langFreq) {
            maxCover = max(maxCover, p.second);
        }

        // Step 4: answer = total conflict users - max covered by one language
        return (int)conflictUsers.size() - maxCover;
    }
