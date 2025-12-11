 int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if (wordset.count(endWord) == 0) {
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        vector<char> charset = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        while (!q.empty()) {
            string currWord = q.front().first;
            int currDist = q.front().second;
            q.pop();
            if (currWord == endWord)
                return currDist;
            for (int i = 0; i < currWord.length(); i++) {
                char original = currWord[i];
                for (char c : charset) {
                    if (c != original) {
                        string next = currWord;
                        next[i] = c;
                        if (wordset.count(next)) {
                            wordset.erase(next);
                            if (next == endWord) {
                                return currDist + 1;
                            }
                            q.push({next, currDist + 1});
                        }
                    }
                }
            }
        }
        return 0;
    }
