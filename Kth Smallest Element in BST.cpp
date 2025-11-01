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
    void inOrder(TreeNode* root,int ind,int &startInd,int &num){
        if(root == nullptr){
            
            return;
        }
        
        inOrder(root->left,ind,startInd,num);
        startInd += 1;
        if(startInd == ind){
            num = root -> val;
            return;
        }
        inOrder(root -> right,ind,startInd,num);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int start = 0;
        int num;
        inOrder(root,k,start,num);
        return num;
    }
};
