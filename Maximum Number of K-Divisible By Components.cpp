class Solution {
private:
    int dfs(vector<int>& values, unordered_map<int, vector<int>>& adjList,
             int curr, int parent, int sum, int& ans, int k) {

        sum = values[curr];

        for (int neighbor : adjList[curr]) {

            if (neighbor != parent) {
                sum += dfs(values, adjList, neighbor, curr, sum, ans, k);
                sum = sum % k;
            }
        }
        sum = sum % k;
        if (sum == 0) {
            ans++;
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int currNode = 0;
        int sum = 0;
        int ans = 0;
        int parent = -1;
        int val = dfs(values, adjList, currNode, parent, sum, ans, k);
        return ans;
    }
};
