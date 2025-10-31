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
int min_diff = INT_MAX;
TreeNode* prev = nullptr;
void inOrder(TreeNode* root){
    
    if(root==nullptr)return;
    inOrder(root->left);
    if(prev != nullptr){
        min_diff = min(min_diff,root->val - prev->val);
    }
    prev = root;
    inOrder(root->right);
}
public:

    int getMinimumDifference(TreeNode* root) {
       
        inOrder(root);
        return min_diff;
    }
};
