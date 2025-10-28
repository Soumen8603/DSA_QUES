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
    vector<double>levelOrder(TreeNode* root){
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int si = q.size();
            int levelSize = si;
            double sum = 0;
            while(si > 0){
                TreeNode* node = q.front();
                q.pop();
                si--;
                sum += node -> val;
                if(node -> left != nullptr){
                    q.push(node -> left);
                }
                if(node -> right != nullptr){
                    q.push(node -> right);
                }
            }
            ans.push_back(sum / levelSize);
        }
        return ans;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)return {};
        vector<double>ans = levelOrder(root);
        return ans;
    }
};
