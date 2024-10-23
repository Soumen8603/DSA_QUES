 TreeNode* replaceValueInTree(TreeNode* root) {
       queue<TreeNode*>q;
       vector<int>levelsum;
       q.push(root);
       //pass1
       while(!q.empty()){
        int size = q.size();
        int sum = 0;
        for(int i = 0;i < size;i++){
        TreeNode* node = q.front();
        q.pop();
        sum += node -> val;
        if(node -> left !=  NULL){
            q.push(node -> left);
        }
        if(node -> right !=  NULL){
            q.push(node -> right);
        }
      }
      levelsum.push_back(sum);
    }

    //pass 2
    root -> val = 0;
    int level = 0;
    
       
    q.push(root);

     while(!q.empty()){
        int size = q.size();
       
        for(int i = 0;i < size;i++){
         int sum = 0;
        TreeNode* node = q.front();
        q.pop();
        if(node -> left !=  NULL){
            sum += node -> left -> val;
        }
        if(node -> right !=  NULL){
             sum += node -> right -> val;
        }

         if(node -> left !=  NULL){
            node -> left -> val = levelsum[level+1] - sum;
            q.push(node -> left); 
        }
        if(node -> right !=  NULL){
            node -> right -> val = levelsum[level+1] - sum;
            q.push(node -> right); 
        }
      }
      level++;
    }

    return root;
    
 }
