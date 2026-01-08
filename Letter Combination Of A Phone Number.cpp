class Solution {
private:
    void solve(string digits, int index, string& curr,
               unordered_map<int, vector<char>>& mp, set<string>& res) {
        if (index == digits.length()) {
            res.insert(curr);
            return;
        }
        int digit = digits[index] - '0';
        for (char c : mp[digit]) {
            curr += c;
            solve(digits, index + 1, curr, mp, res);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        set<string> res;

        string curr = "";
        solve(digits, 0,  curr, mp, res);
        return vector<string>(res.begin(),res.end());
    }
};
