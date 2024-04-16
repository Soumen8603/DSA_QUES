void dfs(TreeNode* root,int currDepth,int depth,int val){
        if(root==NULL){
            return;
        }
        if(currDepth==depth-1){
           TreeNode* leftNode=new TreeNode(val);
            leftNode->left=root->left;
            root->left=leftNode;

            TreeNode* rightNode=new TreeNode(val);
            rightNode->right=root->right;
            root->right=rightNode;
            return;
        }
        dfs(root->left,currDepth+1,depth,val);
        dfs(root->right,currDepth+1,depth,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
           TreeNode* first=new TreeNode(val);
           first->left=root;
            return first;
        }
        dfs(root,1,depth,val);
        return root;
       
    }
