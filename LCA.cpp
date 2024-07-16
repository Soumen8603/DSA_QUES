TreeNode* lca(TreeNode* root,int p,int q){
        //Base case
        if(root == NULL || root->val == p || root->val == q){
            return root;
        }

        TreeNode* left = (root->left,p,q);
        TreeNode* right = (root->right,p,q);

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            //We found our result both are not null
            return root;
        }
    }
