/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == nullptr)
            return;
        if (level >= res.size()) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        levelOrder(root->left, level + 1, res);
        levelOrder(root->right, level + 1, res);
    }

public:
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        long long maxSum = LLONG_MIN;
        int levelMax = -1;
        for (int i = 0; i < res.size(); i++) {
            long long sum = 0;
            for (int j = 0; j < res[i].size(); j++) {
                sum += res[i][j];
            }
            if (sum > maxSum) {
                maxSum = sum;
                levelMax = i;
            }
        }
        return levelMax+1;
    }
};
