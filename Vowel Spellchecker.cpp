class Solution {
private:
    bool isVowel(char ch) {
        char input = tolower(ch);
        if (input == 'a' || input == 'e' || input == 'i' || input == 'o' ||
            input == 'u') {
            return true;
        } else {
            return false;
        }
    }
    string convert_small(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
    string convert_mask(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (isVowel(str[i])) {
                str[i] = '*';
            }
        }
        return str;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_map<string, int> mp;
        unordered_map<string, int> converted_map;
        unordered_map<string, int> masked_map;
        vector<string> ans(queries.size(), "");

        for (int i = 0; i < wordlist.size(); i++) {
            mp[wordlist[i]]++;
        }

        for (int i = 0; i < wordlist.size(); i++) {
            string input = convert_small(wordlist[i]);
            if (converted_map.find(input) == converted_map.end()) {
                converted_map[input] = i;
            }
        }

        for (int i = 0; i < wordlist.size(); i++) {
            string input = convert_small(wordlist[i]);
            input = convert_mask(input);
            if (masked_map.find(input) == masked_map.end()) {
                masked_map[input] = i;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            if (mp[queries[i]] > 0) {
                ans[i] = queries[i];
            } else {
                string input = convert_small(queries[i]);
                if (converted_map.find(input) != converted_map.end()) {
                    ans[i] = wordlist[converted_map[input]];
                    continue;
                }
                input = convert_mask(input);
                if (masked_map.find(input) != masked_map.end()) {
                    ans[i] = wordlist[masked_map[input]];
                    continue;
                }
            }
        }
        return ans;
    }
};
