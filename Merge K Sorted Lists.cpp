ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(int i = 0;i < lists.size();i++){
            
            ListNode* head = lists[i];
            while(head != NULL){
                arr.push_back(head -> val);
                head = head -> next;
            }
            
        }
        ListNode* prev = new ListNode();
        if(arr.size() == 0){
            return prev -> next;
        }
       sort(arr.begin(),arr.end());
       ListNode* currPrev = prev;
       for(int i = 0;i < arr.size();i++){
        ListNode* curr = new ListNode(arr[i]);
        currPrev -> next = curr;
        currPrev = curr;
       }
       return prev -> next;
    }
