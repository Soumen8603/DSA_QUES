bool wordPattern(string pattern, string s) {
        vector<string> words;
        std::istringstream stream(s);
        std::string word;
        while (std::getline(stream, word, ' ')) {
            words.push_back(word);
        }
        if (pattern.size() < words.size() || pattern.size() > words.size()) {
            return false;
        }
        unordered_map<string, char> check;
        unordered_map<char, string> mp;
        for (int i = 0; i < pattern.size(); i++) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (check.find(words[i]) == check.end()) {
                    mp[pattern[i]] = words[i];
                    check[words[i]] = pattern[i];
                } else {
                    if (check[words[i]] != pattern[i]) {
                        return false;
                    }
                }
            } else {
                if (mp[pattern[i]] != words[i]) {
                    return false;
                }
            }
        }
        return true;
    }
