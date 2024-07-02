bool compute(Node* head) {
        // Your code goes here
        string s;
        Node* temp=head;
        while(temp!=NULL){
            s+=temp->data;
            temp=temp->next;
        }
        string ans=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        for(int i=0;i<n;i++){
            if(ans[i]!=s[i]){
                return false;
            }
        }
        return true;
    }
