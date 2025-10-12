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
    // int search(vector<int>& inorder,int left,int right,int value){
    //     for(int i = left;i <= right;i++){
    //         if(inorder[i] ==  value){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    // TreeNode* build(vector<int>& preorder, vector<int>& inorder,int left,int right,int &preIndex){
    //     if(left > right)return nullptr;
    //     int rootVal = preorder[preIndex];
    //     preIndex++;
    //     TreeNode* root = new TreeNode(rootVal);
    //     int index = search(inorder,left,right,rootVal);
    //     root->left = build(preorder,inorder,left,index-1,preIndex);
    //     root->right = build(preorder,inorder,index+1,right,preIndex);
    //     return root;
    // }
    TreeNode* build(vector<int>& preorder, unordered_map<int,int>&mp,int left,int right,int &preIndex){
        if(left > right)return nullptr;
        int rootVal = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(rootVal);
        int index = mp[rootVal];
        root->left = build(preorder,mp,left,index-1,preIndex);
        root->right = build(preorder,mp,index+1,right,preIndex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int preIndex = 0;
        for(int i = 0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root =  build(preorder,mp,0,preorder.size()-1,preIndex);
        return root;
    }
};
