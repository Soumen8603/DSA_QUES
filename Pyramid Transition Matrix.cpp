class Solution {
private:
    unordered_map<string, bool> memo;
    unordered_map<string, vector<char>> mp;

    bool solve(string current_row, string next_row) {
        if (current_row.length() == 1) {
            return true;
        }

        if (next_row.length() == current_row.length() - 1) {
            if (memo.count(next_row)) return memo[next_row];
            return memo[next_row] = solve(next_row, "");
        }

        int i = next_row.length();
        string pair = current_row.substr(i, 2);

        if (mp.count(pair)) {
            for (char top_block : mp[pair]) {
                if (solve(current_row, next_row + top_block)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memo.clear();
        mp.clear();

        for (const string& s : allowed) {
            string key = s.substr(0, 2);
            mp[key].push_back(s[2]);
        }

        return solve(bottom, "");
    }
};
