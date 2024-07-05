 void calculate(Node* root,int rootdist,unordered_set<int>&st){
        if(root==NULL){
            return;
        }
        st.insert(rootdist);
        calculate(root->left,rootdist-1,st);
        calculate(root->right,rootdist+1,st);
        
    }
    int verticalWidth(Node* root) {
        // code here
        int rootdist=0;
        unordered_set<int>st;
        calculate(root,rootdist,st);
        return st.size();
        
    }
