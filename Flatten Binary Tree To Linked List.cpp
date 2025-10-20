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
    TreeNode* prev = nullptr;
private:
    void convert(TreeNode* root){
        if(root == nullptr)return;
        TreeNode* originalLeft = root -> left;
        TreeNode* originalRight = root -> right;
        if(prev != nullptr){
            prev -> left = nullptr;
            prev -> right = root;
        }
        prev = root;
        convert(originalLeft);
        convert(originalRight);

    }
public:
    void flatten(TreeNode* root) {
        prev = nullptr;
        convert(root);
        
    }
};
