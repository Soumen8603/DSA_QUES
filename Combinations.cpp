
// Pick - Non Pick Approach
class Solution {
private:
    void solve(int n, int start, vector<int>& curr, int k,
               vector<vector<int>>& ans) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        if (start > n || curr.size() + (n - start + 1) < k) {
            return;
        }
        curr.push_back(start);
        solve(n, start + 1, curr, k, ans);
        curr.pop_back();
        solve(n, start + 1, curr, k, ans);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        int start = 1;
        solve(n, start, curr, k, ans);
        return ans;
    }
};


// For Loop Backtracking Approach

class Solution {
private:
    void solve(int n, int start, vector<int>& curr, int k,
               vector<vector<int>>& ans) {
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        for(int i = start;i <= n;i++){
            curr.push_back(i);
            solve(n,i+1,curr,k,ans);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        int start = 1;
        solve(n, start, curr, k, ans);
        return ans;
    }
};
