 ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (prev->next && prev->next->val < x) {
        prev = prev->next;
    }
    
    ListNode* currprev = prev;
    ListNode* curr = prev->next;
    
    while (curr) {
        if (curr->val < x) {
            currprev->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            prev = curr;
            curr = currprev->next;
        } else {
            currprev = curr;
            curr = curr->next;
        }
    }
    
    return dummy->next;
    }
