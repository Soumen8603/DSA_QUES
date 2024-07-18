int goodleaf;
   vector<int>dfs(TreeNode* node , int dist){
    if(node== nullptr)return{};

    if(node->left == NULL && node->right==NULL)return{1};

    vector<int>leftv=dfs(node->left,dist);
    vector<int>rightv = dfs(node->right , dist);

    for(auto i : leftv){
        for(auto j : rightv){
            if(i+j <= dist)goodleaf++;
        }
    }

    vector<int>parent;

    for(auto i : leftv){
        if(i+1 < dist){
            parent.push_back(i+1);
        }
    }

    for(auto i : rightv){
        if(i+1 < dist){
            parent.push_back(i+1);
        }
    }

    return parent;


   }
    int countPairs(TreeNode* root, int distance) {
       goodleaf=0; 
       dfs(root,distance);
       return goodleaf;
    }
