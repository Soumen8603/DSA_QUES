 ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0)
            return head;
        int length = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }
        if (length == 0 || length == 1)
            return head;
        if (k == length || k % length == 0) {
            return head;
        }
        if (k > length) {
            k = k % length;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* currHead = head;
        curr = head;
        int count = 1;
        while (count < length - k) {
            curr = curr->next;
            count++;
        }
        ListNode* endNode = curr;
        curr = curr->next;
        ListNode* newNodeprev = curr;
        ListNode* newNodeend = curr;
        curr = curr->next;
        while (curr != NULL) {
            newNodeend = curr;
            curr = curr->next;
        }

        endNode->next = NULL;
        dummy->next = newNodeprev;
        newNodeend->next = currHead;
        return dummy->next;
    }
