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
    vector<int> levelOrder(TreeNode* root){
        if(root == nullptr)return {};
        queue<TreeNode*>q;
        int currLevel = 0;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int qu_size = q.size();
            while(qu_size > 0){
                TreeNode* curr = q.front();
                if(qu_size == 1){
                    ans.push_back(curr->val);
                }
                q.pop();
                qu_size--;
                if(curr -> left != nullptr){
                    q.push(curr -> left);
                }
                if(curr -> right != nullptr){
                    q.push(curr -> right);
                }

            }
        }
        return ans;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans = levelOrder(root);
        return ans;
    }
};
