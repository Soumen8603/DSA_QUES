 ListNode* mergeNodes(ListNode* head) {
        ListNode* node=head;
        ListNode* ans=NULL;
        ListNode* ansI=NULL;
        while(node!=NULL){
            ListNode* start=node->next;
            int value=0;
            while(start!=NULL && start->val!=0){
                value+=start->val;
                start=start->next;
            }
            if(value!=0){
                if(ans==NULL){
                    ans=new ListNode(value);
                    ansI=ans;
                }
                else{
                    ansI->next=new ListNode(value);
                    ansI=ansI->next;
                }
            }
            node=start;
        }
        return ans;
    }
