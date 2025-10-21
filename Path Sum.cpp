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
private:
    bool check(TreeNode* root, int targetSum,int sum){
        sum += root -> val;
        if(sum == targetSum && root->left == nullptr && root -> right == nullptr)return true;
        if(root->left == nullptr && root -> right == nullptr)return false;
        bool check1,check2;
        if(root -> left != nullptr){
            check1 = check(root -> left,targetSum,sum);
        }
        if(root -> right != nullptr){
            check2 = check(root -> right,targetSum,sum);
        }
        if(check1 || check2)return true;
        return false;

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)return false;
        int sum = 0;
        return check(root,targetSum,sum);
    }
};
