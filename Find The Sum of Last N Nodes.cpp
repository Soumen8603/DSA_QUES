int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        struct Node* curr = head;
        int len = 0;
        while(curr != NULL){
            len++;
            curr = curr -> next;
        }
        struct Node* curr1 = head;
        int sum = 0;
        while(curr1 != NULL){
            
            if(len <= n){
                sum += curr1 -> data;
            }
            curr1 = curr1 -> next;
            len--;
        }
        return sum;
    }
