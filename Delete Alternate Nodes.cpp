void deleteAlt(struct Node *head) {
        // Code here
        Node* curr = head;
        
        
        
        while(curr->next != NULL && curr->next->next != NULL){
            curr -> next = curr -> next -> next;
            curr = curr -> next;
        }
        curr -> next = NULL;
    }
