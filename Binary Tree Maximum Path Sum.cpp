/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxSum;
public:
    int helper(TreeNode* root){
        if(root == nullptr)return 0;
        int left = max(0,helper(root -> left));
        int right = max(0,helper(root -> right));
        maxSum = max(maxSum,root->val+left+right);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }
};
