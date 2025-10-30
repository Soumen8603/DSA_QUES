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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool  rev = true;
        while(!q.empty()){
            vector<int>vec;
            int si = q.size();
            while(si > 0){
                TreeNode* node = q.front();
                q.pop();
                si--;
                vec.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
           if(rev == true){
            ans.push_back(vec);
            rev = false;
           }
           else{
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            rev = true;
           }
        }
        return ans;
    }
};
