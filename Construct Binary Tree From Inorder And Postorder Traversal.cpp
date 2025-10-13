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
    TreeNode* build(vector<int>& postorder,unordered_map<int,int>&mp,int left,int right,int &postIndex){
        if(left > right)return nullptr;
        int rootval = postorder[postIndex];
        TreeNode* root = new TreeNode(rootval);
        postIndex--;
        int index = mp[rootval];
        root -> right = build(postorder,mp,index+1,right,postIndex);
        root -> left = build(postorder,mp,left,index-1,postIndex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i = 0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        int left = 0;
        int right = postIndex;
        TreeNode* root = build(postorder,mp,left,right,postIndex);
        return root;
    }
};
