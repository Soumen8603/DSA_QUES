class Solution {
private:
    void solve(vector<int>& nums, vector<bool>& visited,
               vector<vector<int>>& ans, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                curr.push_back(nums[i]);
                solve(nums, visited, ans, curr);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, visited, ans, curr);
        return ans;
    }
};
