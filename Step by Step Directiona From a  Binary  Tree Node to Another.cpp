TreeNode* lca(TreeNode* root,int p,int q){
        //Base case
        if(root == NULL || root->val == p || root->val == q){
            return root;
        }

        TreeNode* leftn = lca(root->left,p,q);
        TreeNode* rightn = lca(root->right,p,q);

        if(leftn == NULL){
            return rightn;
        }
        else if(rightn == NULL){
            return leftn;
        }
        else{
            //We found our result both are not null
            return root;
        }
    }

    string lcatostart,lcatoend;
    void dfs(TreeNode* node , string& pathstring , int p , int q){
          if(node == nullptr)return;
          if(node->val == p)lcatostart=pathstring;
          if(node->val == q)lcatoend=pathstring;

          pathstring.push_back('L');
          dfs(node->left,pathstring,p,q);
          pathstring.pop_back();

          pathstring.push_back('R');
          dfs(node->right,pathstring,p,q);
          pathstring.pop_back();

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcanode = lca(root , startValue , destValue);
        string pathstring="";
        dfs(lcanode , pathstring , startValue , destValue);

        for(auto& ch : lcatostart)ch='U';
        return lcatostart+lcatoend;
    }
