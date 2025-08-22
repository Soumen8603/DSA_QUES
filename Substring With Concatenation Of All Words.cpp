vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) {
            return ans;
        }
        int n = words.size();
        int wordlen = words[0].size();
        
        
        if (wordlen * n > s.size()) {
            return ans;
        }
        unordered_map<string, int> wordCount;
        for (auto& word : words) {
            wordCount[word]++;
        }

        int count;
        for (int i = 0; i < wordlen; i++) {
            int left = i;
            count = 0;
            unordered_map<string, int> seen;
            for (int j = i; j + wordlen <= s.size(); j += wordlen) {
                string word = s.substr(j, wordlen);
                if (wordCount.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordCount[word]) {
                        string leftword = s.substr(left, wordlen);
                        seen[leftword]--;
                        count--;
                        left += wordlen;
                    }
                    if (count == n) {
                        ans.push_back(left);
                    }
                } else {

                    seen.clear();
                    count = 0;
                    left = j + wordlen;
                }
            }
        }
        return ans;
    }
