void populateNext(Node *root) {
        // code here
        Node* p=NULL;
        
        while(root!=NULL){
            if(root->left==NULL){
                if(p==NULL){
                    p=root;
                }
                else{
                    p->next=root;
                    p=p->next;
                }
                root=root->right;
            }
            else{
                Node* curr=root->left;
                while(curr->right!=NULL && curr->right!=root){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    curr->right=root;
                    root=root->left;
                }
                else{
                    curr->right=NULL;
                    if(p==NULL){
                        p=root;
                    }
                    else{
                        p->next=root;
                        p=p->next;
                    }
                    root=root->right;
                }
            }
            
        }
    }
