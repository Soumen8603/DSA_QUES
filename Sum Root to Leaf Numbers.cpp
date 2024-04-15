int sum=0;
   void getPathSum(TreeNode* root,int curr){
    if(root==NULL){
        return;
    }
    curr=curr*10+root->val;
    if(root->left==NULL && root->right==NULL){
        sum+=curr;
        return;
    }
    getPathSum(root->left,curr);
    getPathSum(root->right,curr);
   }

    int sumNumbers(TreeNode* root) {
      
        getPathSum(root,0);
        return sum;

    }
