Node *RemoveHalfNodes(Node *root) {
        // code here
        if(root == NULL)return NULL;
        
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        
        if(root->left == NULL && root->right != NULL)return root->right;
        if(root->left != NULL && root->right == NULL)return root->left;
        
        return root;
        
        
    }
