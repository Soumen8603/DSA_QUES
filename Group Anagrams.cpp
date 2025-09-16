class Solution {
    string generate_freq(vector<int>& char_freq) {
        string generated = "";
        for (int i = 0; i < 26; i++) {
            if (char_freq[i] > 0) {
                generated += to_string(char_freq[i]); // number
                generated += (char)('a' + i);         // character
            }
        }
        return generated;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        int count = 0;
        for (int i = 0; i < strs.size(); i++) {
            string ex = strs[i];
            vector<int> char_freq(26, 0);
            for (int i = 0; i < ex.size(); i++) {
                char_freq[ex[i] - 'a']++;
            }
            string generated = generate_freq(char_freq);
            if (mp.find(generated) == mp.end()) {
                mp[generated] = count;
                count++;
            }
        }
        for (const auto& pair : mp) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second
                      << std::endl;
        }
        vector<vector<string>> ans(mp.size());
        for (int i = 0; i < strs.size(); i++) {
            string ex = strs[i];
            vector<int> char_freq(26, 0);
            for (int i = 0; i < ex.size(); i++) {
                char_freq[ex[i] - 'a']++;
            }
            string generated = generate_freq(char_freq);
            ans[mp[generated]].push_back(strs[i]);
        }
        return ans;
    }
};
