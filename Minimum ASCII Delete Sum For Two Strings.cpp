class Solution {
private:
    int solve(string& s1, string& s2, int index1, int index2,
              vector<vector<int>>& dp) {
        if (index1 == 0) {
            int sum = 0;
            for (int i = 0; i < index2; i++)
                sum += s2[i];
            return sum;
        }
        if (index2 == 0) {
            int sum = 0;
            for (int i = 0; i < index1; i++)
                sum += s1[i];
            return sum;
        }

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (s1[index1 - 1] == s2[index2 - 1]) {
            return dp[index1][index2] = solve(s1, s2, index1 - 1, index2 - 1,dp);
        } else {
            return dp[index1][index2] = min(
                       (int)s1[index1 - 1] + solve(s1, s2, index1 - 1, index2,dp),
                       (int)s2[index2 - 1] + solve(s1, s2, index1, index2 - 1,dp));
        }
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(s1, s2, m, n, dp);
    }
};
