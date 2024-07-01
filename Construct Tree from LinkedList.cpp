void constructTree(vector<int>&v,int ind,TreeNode* &node){
    node=new TreeNode(v[ind]);
    
    int leftInd=ind*2+1,rightInd=ind*2+2;
    
    if(leftInd<v.size()){
        constructTree(v,leftInd,node->left);
    }
    else{
        return;
    }
    
    if(rightInd<v.size()){
        constructTree(v,rightInd,node->right);
    }
}

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    vector<int>v;
    Node* temp=head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    constructTree(v,0,root);
    
}
