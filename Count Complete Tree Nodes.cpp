 int countNodes(TreeNode* root) {
        if(root == nullptr)return 0;
        int left_count = countNodes(root -> left);
        int right_count = countNodes(root -> right);
        return 1 + left_count + right_count;
        
    }
