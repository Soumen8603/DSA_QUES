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
    void levelOrderRec(TreeNode* root,vector<vector<TreeNode*>>&res,int level){
        if(root == nullptr)return;
        if(res.size() <= level){
            res.push_back({});
        }
        res[level].push_back(root);
        levelOrderRec(root->left,res,level+1);
        levelOrderRec(root->right,res,level+1);
    }
    vector<vector<TreeNode*>>levelOrder(TreeNode* root){
        vector<vector<TreeNode*>>res;
        levelOrderRec(root,res,0);
        return res;
    }
    TreeNode* LCA(int left,int right,TreeNode* root){
        if(!root)return nullptr;
        if(root -> val == left || root -> val == right)return root;
        TreeNode* leftLCA = LCA(left,right,root->left);
        TreeNode* rightLCA = LCA(left,right,root->right);
        if(leftLCA && rightLCA)return root;
        return leftLCA ? leftLCA : rightLCA;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>>levelVector = levelOrder(root);
        int n = levelVector.size();
        int m = levelVector[n-1].size();
        if(m == 1){
            return levelVector[n-1][0];
        }
        int leftVal = levelVector[n-1][0] -> val;
        int rightVal = levelVector[n-1][m-1] -> val;
        return LCA(leftVal,rightVal,root);
    }
};
