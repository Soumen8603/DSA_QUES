Node* removeAllDuplicates(struct Node* head) {
        // code here
        map<int,int>mp;
        Node* temp=head;
        while(temp!=NULL){
            mp[temp->data]++;
            temp = temp->next;

        }
        
        
        Node* dummy=new Node(0);
        Node* prev=dummy;
       
        dummy->next=NULL;
        
     for(auto it: mp){
         if(it.second==1){
             Node* newNode=new Node(it.first);
             prev->next=newNode;
             prev=newNode;
         }
     }
        return dummy->next;
        
    }
