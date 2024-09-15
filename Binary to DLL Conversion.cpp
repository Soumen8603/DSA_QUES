 Node* head = NULL;
  Node* prev = NULL;

    Node* bToDLL(Node* root) {
        // code here
        if(!root)return NULL;
        
        bToDLL(root -> left);
        if(prev == NULL){
            head=root;
        }
        else{
            prev -> right = root;
            prev -> right -> left = prev;
        }
        prev = root;
         bToDLL(root -> right);
         return head;
    }
